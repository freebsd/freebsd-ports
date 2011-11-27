--- libc/error.c.orig	1988-12-30 10:50:06.000000000 +0100
+++ libc/error.c	2010-10-08 19:38:21.000000000 +0200
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 extern void warning();
 
