--- util/newslock.c.orig	1989-05-22 04:12:16.000000000 +0200
+++ util/newslock.c	2011-05-12 14:51:20.000000000 +0200
@@ -4,6 +4,7 @@
  * (System V has broken ln(1) itself.)
  */
 #include <stdio.h>
+#include <stdlib.h>
 
 main(argc, argv)
 int argc;
