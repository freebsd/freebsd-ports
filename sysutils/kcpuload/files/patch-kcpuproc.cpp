--- kcpuload/kcpuproc.cpp.orig	Wed May  7 09:07:19 2003
+++ kcpuload/kcpuproc.cpp	Wed May  7 09:16:42 2003
@@ -18,8 +18,12 @@
 
 // BSD-specific includes.
 #ifdef Q_OS_BSD4
-#include <sys/dkstat.h>
 #include <sys/param.h>
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500101
+#include <sys/resource.h>
+#else
+#include <sys/dkstat.h>
+#endif
 #include <sys/sysctl.h>
 #include <string.h>
 #include <kvm.h>
