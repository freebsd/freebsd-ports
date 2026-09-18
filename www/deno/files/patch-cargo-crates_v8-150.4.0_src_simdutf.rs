--- cargo-crates/v8-150.4.0/src/simdutf.rs.orig	2026-09-17 22:38:34 UTC
+++ cargo-crates/v8-150.4.0/src/simdutf.rs
@@ -87,6 +87,16 @@ unsafe extern "C" {
     length: usize,
     output: *mut u8,
   ) -> usize;
+  fn simdutf__convert_utf8_to_utf16be_with_errors(
+    input: *const u8,
+    length: usize,
+    output: *mut u16,
+  ) -> FfiResult;
+  fn simdutf__convert_utf16be_to_utf8_with_errors(
+    input: *const u16,
+    length: usize,
+    output: *mut u8,
+  ) -> FfiResult;
 
   // Conversion: UTF-8 <-> Latin-1
   fn simdutf__convert_utf8_to_latin1(
@@ -530,6 +540,84 @@ pub unsafe fn convert_utf16be_to_utf8(
       input.len(),
       output.as_mut_ptr(),
     )
+  }
+}
+
+/// Converts UTF-8 to UTF-16BE with error reporting.
+///
+/// # Safety
+///
+/// `output` must have at least `input.len()` elements of capacity.
+#[inline]
+pub unsafe fn convert_utf8_to_utf16be_with_errors(
+  input: &[u8],
+  output: &mut [u16],
+) -> SimdUtfResult {
+  SimdUtfResult::from_ffi(unsafe {
+    simdutf__convert_utf8_to_utf16be_with_errors(
+      input.as_ptr(),
+      input.len(),
+      output.as_mut_ptr(),
+    )
+  })
+}
+
+/// Converts UTF-16BE to UTF-8 with error reporting.
+///
+/// # Safety
+///
+/// `output` must have at least `input.len() * 3` bytes of capacity.
+#[inline]
+pub unsafe fn convert_utf16be_to_utf8_with_errors(
+  input: &[u16],
+  output: &mut [u8],
+) -> SimdUtfResult {
+  SimdUtfResult::from_ffi(unsafe {
+    simdutf__convert_utf16be_to_utf8_with_errors(
+      input.as_ptr(),
+      input.len(),
+      output.as_mut_ptr(),
+    )
+  })
+}
+
+// ---------------------------------------------------------------------------
+// Conversion: UTF-8 <-> native-endian UTF-16
+// V8 two-byte string data is in the host byte order, so the paths that hand
+// data to V8 or read it back must use these rather than the LE variants.
+// ---------------------------------------------------------------------------
+
+/// Converts UTF-8 to native-endian UTF-16 with error reporting.
+///
+/// # Safety
+///
+/// `output` must have at least `input.len()` elements of capacity.
+#[inline]
+pub unsafe fn convert_utf8_to_utf16_with_errors(
+  input: &[u8],
+  output: &mut [u16],
+) -> SimdUtfResult {
+  if cfg!(target_endian = "little") {
+    unsafe { convert_utf8_to_utf16le_with_errors(input, output) }
+  } else {
+    unsafe { convert_utf8_to_utf16be_with_errors(input, output) }
+  }
+}
+
+/// Converts native-endian UTF-16 to UTF-8 with error reporting.
+///
+/// # Safety
+///
+/// `output` must have at least `input.len() * 3` bytes of capacity.
+#[inline]
+pub unsafe fn convert_utf16_to_utf8_with_errors(
+  input: &[u16],
+  output: &mut [u8],
+) -> SimdUtfResult {
+  if cfg!(target_endian = "little") {
+    unsafe { convert_utf16le_to_utf8_with_errors(input, output) }
+  } else {
+    unsafe { convert_utf16be_to_utf8_with_errors(input, output) }
   }
 }
 
