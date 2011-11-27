--- libc/stdfdopen.c.orig	1990-10-28 08:20:54.000000000 +0100
+++ libc/stdfdopen.c	2011-05-12 14:46:36.000000000 +0200
@@ -4,6 +4,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <errno.h>
 #ifndef __STDC__
 extern int errno;
