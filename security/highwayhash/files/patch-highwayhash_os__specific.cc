--- highwayhash/os_specific.cc.orig	2020-11-29 23:19:18 UTC
+++ highwayhash/os_specific.cc
@@ -53,8 +53,8 @@
 
 #ifdef __FreeBSD__
 #define OS_FREEBSD 1
-#include <sys/cpuset.h>
 #include <sys/param.h>
+#include <sys/cpuset.h>
 #include <unistd.h>
 #else
 #define OS_FREEBSD 0
