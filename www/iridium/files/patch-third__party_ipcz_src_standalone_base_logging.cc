--- third_party/ipcz/src/standalone/base/logging.cc.orig	2025-05-07 06:48:23 UTC
+++ third_party/ipcz/src/standalone/base/logging.cc
@@ -55,6 +55,9 @@ LogMessage::LogMessage(const char* file, int line, Lev
 #elif BUILDFLAG(IS_ANDROID)
   stream_ << getpid() << ":" << gettid() << ":";
   const char* trimmed_file = strrchr(file, '/') + 1;
+#elif BUILDFLAG(IS_BSD)
+  stream_ << getpid() << ":" << pthread_self() << ":";
+  const char* trimmed_file = strrchr(file, '/') + 1;
 #elif BUILDFLAG(IS_WIN)
   const char* trimmed_file = file;
   stream_ << (::GetCurrentProcessId()) << ":" << ::GetCurrentThreadId() << ":";
