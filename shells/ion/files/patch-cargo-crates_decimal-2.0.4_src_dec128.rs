Allow build on aarch64 and maybe powerpc64

https://github.com/alkis/decimal/commit/5577a60b9b8860a322288856ff2419c191ed080f

error[E0308]: mismatched types
   --> .../cargo-crates/decimal-2.0.4/src/dec128.rs:229:35
    |
229 |             decQuadToString(self, buf.as_mut().as_mut_ptr());
    |                                   ^^^^^^^^^^^^^^^^^^^^^^^^^ expected u8, found i8
    |
    = note: expected type `*mut u8`
               found type `*mut i8`

error[E0308]: mismatched types
   --> .../cargo-crates/decimal-2.0.4/src/dec128.rs:230:39
    |
230 |             let cstr = CStr::from_ptr(buf.as_ptr());
    |                                       ^^^^^^^^^^^^ expected u8, found i8
    |
    = note: expected type `*const u8`
               found type `*const i8`

error[E0308]: mismatched types
   --> .../cargo-crates/decimal-2.0.4/src/dec128.rs:249:38
    |
249 |             decQuadToEngString(self, buf.as_mut().as_mut_ptr());
    |                                      ^^^^^^^^^^^^^^^^^^^^^^^^^ expected u8, found i8
    |
    = note: expected type `*mut u8`
               found type `*mut i8`

error[E0308]: mismatched types
   --> .../cargo-crates/decimal-2.0.4/src/dec128.rs:250:39
    |
250 |             let cstr = CStr::from_ptr(buf.as_ptr());
    |                                       ^^^^^^^^^^^^ expected u8, found i8
    |
    = note: expected type `*const u8`
               found type `*const i8`

error: aborting due to 4 previous errors

--- cargo-crates/decimal-2.0.4/src/dec128.rs.orig	2019-05-23 06:18:16 UTC
+++ cargo-crates/decimal-2.0.4/src/dec128.rs
@@ -224,7 +224,7 @@ impl Into<u32> for d128 {
 /// payload is 0.
 impl fmt::Display for d128 {
     fn fmt(&self, fmt: &mut fmt::Formatter) -> fmt::Result {
-        let mut buf = [0 as i8; 43];
+        let mut buf = [0; 43];
         unsafe {
             decQuadToString(self, buf.as_mut().as_mut_ptr());
             let cstr = CStr::from_ptr(buf.as_ptr());
@@ -244,7 +244,7 @@ impl fmt::Debug for d128 {
 /// exponential notation is used the exponent will be a multiple of 3.
 impl fmt::LowerExp for d128 {
     fn fmt(&self, fmt: &mut fmt::Formatter) -> fmt::Result {
-        let mut buf = [0 as i8; 43];
+        let mut buf = [0; 43];
         unsafe {
             decQuadToEngString(self, buf.as_mut().as_mut_ptr());
             let cstr = CStr::from_ptr(buf.as_ptr());
