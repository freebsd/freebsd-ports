--- highwayhash/arch_specific.cc.orig	2020-09-22 06:18:43 UTC
+++ highwayhash/arch_specific.cc
@@ -24,8 +24,8 @@
 #if __GLIBC__
 #include <sys/platform/ppc.h>  // __ppc_get_timebase_freq
 #elif __FreeBSD__
-#include <sys/sysctl.h>
 #include <sys/types.h>
+#include <sys/sysctl.h>
 #endif
 #endif
 
