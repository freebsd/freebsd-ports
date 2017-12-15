--- xpcom/io/nsLocalFileUnix.cpp.orig	2017-11-14 14:36:13 UTC
+++ xpcom/io/nsLocalFileUnix.cpp
@@ -13,9 +13,6 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
-#if !defined(XP_MACOSX)
-#include <sys/sysmacros.h> // No longer implicitly included in later glibc
-#endif
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -31,6 +28,10 @@
 #define USE_LINUX_QUOTACTL
 #include <sys/mount.h>
 #include <sys/quota.h>
+#include <sys/sysmacros.h>
+#ifndef BLOCK_SIZE
+#define BLOCK_SIZE 1024 /* kernel block size */
+#endif
 #endif
 
 #include "xpcom-private.h"
