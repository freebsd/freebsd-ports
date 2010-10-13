--- src/help.cc.orig	2010-10-11 22:21:22.000000000 +0200
+++ src/help.cc	2010-10-11 22:35:32.000000000 +0200
@@ -748,7 +748,10 @@
     return  s=="index.htm";
   }
 #else
-#if defined(__APPLE__) // || defined(__FreeBSD__)
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+#if defined(__APPLE__) || (defined(__FreeBSD_version) && (__FreeBSD_version < 800501))
   static int dir_select (struct dirent *d){
 #else
   static int dir_select (const struct dirent *d){
