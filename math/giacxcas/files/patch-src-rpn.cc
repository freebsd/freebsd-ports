--- src/rpn.cc.orig	2010-10-11 22:21:12.000000000 +0200
+++ src/rpn.cc	2010-10-11 22:07:07.000000000 +0200
@@ -530,7 +530,10 @@
   gen symb_VARS(const gen & a){
     return symbolic(at_VARS,a);
   }
-#if defined(__APPLE__) // || defined(__FreeBSD__)
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+#if defined(__APPLE__) || (defined(__FreeBSD_version) && (__FreeBSD_version < 800501))
   static int int_one (struct dirent *unused){
 #else
   static int int_one (const struct dirent *unused){
