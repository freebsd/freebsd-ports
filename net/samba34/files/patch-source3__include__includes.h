--- ./source3/include/includes.h.orig	2010-01-18 11:38:09.000000000 +0000
+++ ./source3/include/includes.h	2010-02-10 02:08:50.000000000 +0000
@@ -222,6 +222,10 @@
 #include <sys/uio.h>
 #endif
 
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
+
 #if HAVE_LANGINFO_H
 #include <langinfo.h>
 #endif
@@ -755,10 +759,6 @@
 #define SIGCLD SIGCHLD
 #endif
 
-#ifndef SIGRTMIN
-#define SIGRTMIN 32
-#endif
-
 #ifndef MAP_FILE
 #define MAP_FILE 0
 #endif
