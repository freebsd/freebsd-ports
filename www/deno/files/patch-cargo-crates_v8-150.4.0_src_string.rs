--- cargo-crates/v8-150.4.0/src/string.rs.orig	2026-09-17 22:38:34 UTC
+++ cargo-crates/v8-150.4.0/src/string.rs
@@ -551,7 +551,7 @@ impl String {
       let r = unsafe {
         let out =
           std::slice::from_raw_parts_mut(utf16.as_mut_ptr(), buffer.len());
-        crate::simdutf::convert_utf8_to_utf16le_with_errors(buffer, out)
+        crate::simdutf::convert_utf8_to_utf16_with_errors(buffer, out)
       };
       if r.is_ok() {
         // SAFETY: simdutf wrote `r.count` valid UTF-16 code units.
@@ -1360,7 +1360,7 @@ impl<'s> ValueView<'s> {
 // ---------------------------------------------------------------------------
 
 /// The minimum number of UTF-16 code units before we try the SIMD path.
-/// With the single-pass `convert_utf16le_to_utf8_with_errors` conversion the
+/// With the single-pass `convert_utf16_to_utf8_with_errors` conversion the
 /// crossover against the scalar `decode_utf16` loop is low; measured wins start
 /// around 16 units.
 #[cfg(feature = "simdutf")]
@@ -1520,8 +1520,9 @@ fn latin1_to_string(bytes: &[u8]) -> std::string::Stri
   }
 }
 
-/// Converts (potentially ill-formed) UTF-16LE / WTF-16 code units to an
-/// owned [`std::string::String`], replacing unpaired surrogates with U+FFFD.
+/// Converts (potentially ill-formed) native-endian UTF-16 / WTF-16 code units
+/// to an owned [`std::string::String`], replacing unpaired surrogates with
+/// U+FFFD.
 #[inline(always)]
 fn wtf16_to_string(units: &[u16]) -> std::string::String {
   #[cfg(feature = "simdutf")]
@@ -1536,7 +1537,7 @@ fn wtf16_to_string(units: &[u16]) -> std::string::Stri
       // SAFETY: `buf` has `cap` bytes of spare capacity.
       let result = unsafe {
         let out = std::slice::from_raw_parts_mut(buf.as_mut_ptr(), cap);
-        crate::simdutf::convert_utf16le_to_utf8_with_errors(units, out)
+        crate::simdutf::convert_utf16_to_utf8_with_errors(units, out)
       };
       if result.is_ok() {
         // SAFETY: simdutf wrote `result.count` valid UTF-8 bytes.
@@ -1570,7 +1571,7 @@ fn wtf16_into_string(units: &[u16], buf: &mut std::str
       let result = unsafe {
         let out =
           std::slice::from_raw_parts_mut(vec.as_mut_ptr().add(start), cap);
-        crate::simdutf::convert_utf16le_to_utf8_with_errors(units, out)
+        crate::simdutf::convert_utf16_to_utf8_with_errors(units, out)
       };
       if result.is_ok() {
         // SAFETY: simdutf wrote `result.count` valid UTF-8 bytes at `start`.
@@ -1641,7 +1642,7 @@ fn wtf16_to_cow_str<'a, const N: usize>(
         let result = unsafe {
           let out =
             std::slice::from_raw_parts_mut(buffer.as_mut_ptr() as *mut u8, N);
-          crate::simdutf::convert_utf16le_to_utf8_with_errors(units, out)
+          crate::simdutf::convert_utf16_to_utf8_with_errors(units, out)
         };
         if result.is_ok() {
           return unsafe {
