--- libc/warning.c.orig	1991-01-09 20:12:55.000000000 +0100
+++ libc/warning.c	2010-10-08 19:41:45.000000000 +0200
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #ifndef __STDC__
 extern int errno;
