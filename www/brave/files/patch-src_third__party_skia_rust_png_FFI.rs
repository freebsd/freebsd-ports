--- src/third_party/skia/rust/png/FFI.rs.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/skia/rust/png/FFI.rs
@@ -244,6 +244,7 @@ mod ffi {
         type StreamWriter;
         fn write(self: &mut StreamWriter, data: &[u8]) -> EncodingResult;
         fn finish_encoding(stream_writer: Box<StreamWriter>) -> EncodingResult;
+        fn initialize_cpudetect();
     }
 }
 
@@ -1185,3 +1186,11 @@ fn new_writer(
 fn finish_encoding(stream_writer: Box<StreamWriter>) -> ffi::EncodingResult {
     stream_writer.0.finish().as_ref().err().into()
 }
+
+#[allow(unused_variables)]
+fn initialize_cpudetect() {
+    #[cfg(any(target_arch = "aarch64", target_arch = "arm64ec"))]
+    let a = std::arch::is_aarch64_feature_detected!("crc");
+    #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+    let a = std::arch::is_x86_feature_detected!("sse2");
+}
