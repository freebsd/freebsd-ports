--- ./lib/ir/grundform.c.orig	2013-11-14 16:55:02.000000000 +0100
+++ ./lib/ir/grundform.c	2013-11-14 16:55:18.000000000 +0100
@@ -68,6 +68,7 @@
 xs_init()
 {
   char *file = __FILE__;
+	dTHX;
 
   {
     /* DynaLoader is a special case */
