--- auxil/highwayhash/highwayhash/os_specific.cc.orig	2021-07-06 20:10:10 UTC
+++ auxil/highwayhash/highwayhash/os_specific.cc
@@ -53,8 +53,8 @@
 
 #ifdef __FreeBSD__
 #define OS_FREEBSD 1
-#include <sys/cpuset.h>
 #include <sys/param.h>
+#include <sys/cpuset.h>			/* must come after sys/param.h */
 #include <unistd.h>
 #else
 #define OS_FREEBSD 0
