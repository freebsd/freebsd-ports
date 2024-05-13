error: 8th rule of macro `libc_enum` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/macros.rs:260:5
    |
260 | /     (@accumulate_entries
261 | |         name: $BitFlags:ident,
262 | |         $prefix:tt,
263 | |         [$($entries:tt)*],
...   |
266 | |         $($tail:tt)*
267 | |     ) => {
    | |_____^
    |
note: the lint level is defined here
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/lib.rs:47:9
    |
47  | #![deny(unused)]
    |         ^^^^^^
    = note: `#[deny(unused_macro_rules)]` implied by `#[deny(unused)]`

error: 6th rule of macro `sockopt_impl` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/sys/socket/sockopt.rs:157:5
    |
157 |     ($(#[$attr:meta])* $name:ident, SetOnly, $level:expr, $flag:path, usize) =>
    |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

error: 3rd rule of macro `sockopt_impl` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/sys/socket/sockopt.rs:142:5
    |
142 |     ($(#[$attr:meta])* $name:ident, GetOnly, $level:expr, $flag:path, usize) =>
    |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

error: 5th rule of macro `sockopt_impl` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/sys/socket/sockopt.rs:153:5
    |
153 |     ($(#[$attr:meta])* $name:ident, SetOnly, $level:expr, $flag:path, u8) => {
    |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

error: 2nd rule of macro `sockopt_impl` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/sys/socket/sockopt.rs:138:5
    |
138 |     ($(#[$attr:meta])* $name:ident, GetOnly, $level:expr, $flag:path, u8) => {
    |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

error: 4th rule of macro `sockopt_impl` is never used
   --> /usr/ports/shells/ion/work/nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/sys/socket/sockopt.rs:148:5
    |
148 |     ($(#[$attr:meta])* $name:ident, SetOnly, $level:expr, $flag:path, bool) => {
    |     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



--- ../nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/lib.rs.orig	2024-05-13 17:53:23 UTC
+++ ../nix-ff6f8b8a26c8d61f4341e441acf405402b46a430/src/lib.rs
@@ -44,7 +44,6 @@
 #![allow(non_camel_case_types)]
 #![cfg_attr(test, deny(warnings))]
 #![recursion_limit = "500"]
-#![deny(unused)]
 #![allow(unused_macros)]
 #![cfg_attr(not(feature = "default"), allow(unused_imports))]
 #![deny(unstable_features)]
