--- third_party/perfetto/src/traced/service/service.cc.orig	2021-07-19 18:47:29 UTC
+++ third_party/perfetto/src/traced/service/service.cc
@@ -29,7 +29,8 @@
 #include "src/traced/service/builtin_producer.h"
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_SET_SOCKET_PERMISSIONS
 #include <fcntl.h>
 #include <grp.h>
