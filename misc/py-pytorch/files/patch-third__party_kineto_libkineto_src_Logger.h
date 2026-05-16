-- Mark errnum_ with [[maybe_unused]] because it is only read inside #ifdef __linux__
-- code; Clang emits -Wunused-private-field on FreeBSD without this annotation.
--- third_party/kineto/libkineto/src/Logger.h.orig	2026-05-16 03:52:38 UTC
+++ third_party/kineto/libkineto/src/Logger.h
@@ -134,7 +134,7 @@ class Logger {
  private:
   std::stringstream buf_;
   std::ostream& out_;
-  int errnum_;
+  [[maybe_unused]] int errnum_;
   int messageSeverity_;
   static std::atomic_int severityLevel_;
   static std::atomic_int verboseLogLevel_;
