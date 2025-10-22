--- third_party/skia/experimental/rust_png/ffi/FFI.rs.orig	2025-10-21 16:57:35 UTC
+++ third_party/skia/experimental/rust_png/ffi/FFI.rs
@@ -219,6 +219,7 @@ mod ffi {
         type StreamWriter;
         fn write(self: &mut StreamWriter, data: &[u8]) -> EncodingResult;
         fn finish_encoding(stream_writer: Box<StreamWriter>) -> EncodingResult;
+        fn initialize_cpudetect();
     }
 }
 
@@ -883,4 +884,12 @@ fn new_writer(
 /// See also https://docs.rs/png/latest/png/struct.StreamWriter.html#method.finish
 fn finish_encoding(stream_writer: Box<StreamWriter>) -> ffi::EncodingResult {
     stream_writer.0.finish().as_ref().err().into()
+}
+
+#[allow(unused_variables)]
+fn initialize_cpudetect() {
+    #[cfg(any(target_arch = "aarch64", target_arch = "arm64ec"))]
+    let a = std::arch::is_aarch64_feature_detected!("crc");
+    #[cfg(any(target_arch = "x86", target_arch = "x86_64"))]
+    let a = std::arch::is_x86_feature_detected!("sse2");
 }
