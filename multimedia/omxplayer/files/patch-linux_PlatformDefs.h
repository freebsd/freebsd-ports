--- linux/PlatformDefs.h.orig	2015-10-24 12:09:14 UTC
+++ linux/PlatformDefs.h
@@ -39,11 +39,11 @@
 #include <unistd.h>
 #include <pthread.h>
 #include <string.h>
-#ifdef __APPLE__
+#if defined(__APPLE__)
 #include <stdio.h>
 #include <sys/sysctl.h>
 #include <mach/mach.h>
-#else
+#elif defined(__linux__)
 #include <sys/sysinfo.h>
 #endif
 #include <sys/time.h>
@@ -416,8 +416,12 @@ typedef struct _SECURITY_ATTRIBUTES {
 #define FILE_CURRENT            1
 #define FILE_END                2
 
+#ifndef _S_IFREG
 #define _S_IFREG  S_IFREG
+#endif
+#ifndef _S_IFDIR
 #define _S_IFDIR  S_IFDIR
+#endif
 #define MAX_PATH PATH_MAX
 
 #define _stat stat
