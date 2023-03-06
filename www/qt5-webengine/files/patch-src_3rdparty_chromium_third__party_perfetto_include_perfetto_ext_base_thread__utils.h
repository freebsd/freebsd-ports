--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/thread_utils.h
@@ -47,6 +47,9 @@ inline bool MaybeSetThreadName(const std::string& name
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE)
   return pthread_setname_np(buf) == 0;
+#elif PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
+  pthread_set_name_np(pthread_self(), buf);
+  return true;
 #else
   return pthread_setname_np(pthread_self(), buf) == 0;
 #endif
