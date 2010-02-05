--- ./source3/include/includes.h.orig	2010-01-18 12:38:09.000000000 +0100
+++ ./source3/include/includes.h	2010-01-22 02:42:50.000000000 +0100
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
@@ -756,7 +760,7 @@
 #endif
 
 #ifndef SIGRTMIN
-#define SIGRTMIN 32
+#define SIGRTMIN NSIG
 #endif
 
 #ifndef MAP_FILE
