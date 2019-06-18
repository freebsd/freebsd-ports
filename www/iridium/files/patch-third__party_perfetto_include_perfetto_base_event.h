--- third_party/perfetto/include/perfetto/base/event.h.orig	2019-03-11 22:08:02 UTC
+++ third_party/perfetto/include/perfetto/base/event.h
@@ -20,8 +20,9 @@
 #include "perfetto/base/build_config.h"
 #include "perfetto/base/scoped_file.h"
 
-#if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+#if (PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_USE_EVENTFD() 1
 #else
 #define PERFETTO_USE_EVENTFD() 0
