--- ./source3/include/includes.h.orig	2010-04-01 15:26:22.000000000 +0200
+++ ./source3/include/includes.h	2010-04-23 01:08:35.000000000 +0200
@@ -226,6 +226,10 @@
 #include <sys/uio.h>
 #endif
 
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
+
 #if HAVE_LANGINFO_H
 #include <langinfo.h>
 #endif
@@ -801,10 +805,6 @@
 #define SIGCLD SIGCHLD
 #endif
 
-#ifndef SIGRTMIN
-#define SIGRTMIN NSIG
-#endif
-
 #ifndef MAP_FILE
 #define MAP_FILE 0
 #endif
