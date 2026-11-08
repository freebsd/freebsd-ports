-- Mark errnum_ with [[maybe_unused]] because it is only read inside #ifdef __linux__
-- code; Clang emits -Wunused-private-field on FreeBSD without this annotation.
--- third_party/kineto/libkineto/src/Logger.h.orig	2026-10-28 18:15:59 UTC
+++ third_party/kineto/libkineto/src/Logger.h
@@ -154,7 +154,7 @@ class Logger {
  private:
   std::stringstream buf_;
   std::ostream& out_;
-  int errnum_;
+  [[maybe_unused]] int errnum_;
   int messageSeverity_;
   static std::atomic_int severityLevel_;
   static std::atomic_int verboseLogLevel_;
