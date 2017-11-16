/*
 * Copyright (c) 2015 - present Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

namespace f1 {
int get() { return 1; }
int get0() { return 0; }
}

namespace f2 {
int get() { return -1; }
}

int div0_using() {
  using namespace f1;
  return 1 / get0();
}

int div0_namespace_resolution() { return 1 / (f1::get() + f2::get()); }

namespace f3 {
class C {
 public:
  static int ret_zero() { return 0; }
};
} // namespace f3

int using_div0() {
  using f3::C;
  return 1 / C::ret_zero();
}

int type_alias_div0() {
  using my_int = int;
  my_int x = 0;
  return 1 / x;
}
