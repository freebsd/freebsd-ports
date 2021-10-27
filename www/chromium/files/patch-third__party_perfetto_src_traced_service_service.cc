--- third_party/perfetto/src/traced/service/service.cc.orig	2021-09-14 01:58:28 UTC
+++ third_party/perfetto/src/traced/service/service.cc
@@ -30,7 +30,8 @@
 #include "src/traced/service/builtin_producer.h"
 
 #if PERFETTO_BUILDFLAG(PERFETTO_OS_LINUX) || \
-    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID)
+    PERFETTO_BUILDFLAG(PERFETTO_OS_ANDROID) || \
+    PERFETTO_BUILDFLAG(PERFETTO_OS_FREEBSD)
 #define PERFETTO_SET_SOCKET_PERMISSIONS
 #include <fcntl.h>
 #include <grp.h>
