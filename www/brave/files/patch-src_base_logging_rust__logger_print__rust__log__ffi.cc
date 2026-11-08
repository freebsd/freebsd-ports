--- src/base/logging/rust_logger/print_rust_log_ffi.cc.orig	2026-06-01 00:00:00 UTC
+++ src/base/logging/rust_logger/print_rust_log_ffi.cc
@@ -27,9 +27,13 @@
                     const char* file,
                     int32_t line,
                     int32_t severity) {
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
+  // Defined in the chromium_src override of this file, which is unavailable
+  // here.
   if (!ShouldPrintRustLog(severity)) {
     return;
   }
+#endif
   LogMessageRustWrapper wrapper(file, line, severity);
   msg.format(wrapper);
 }
