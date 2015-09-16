--- include/unix.h.orig	2015-07-13 22:14:41 UTC
+++ include/unix.h
@@ -11,7 +11,9 @@
 #define _FILE_OFFSET_BITS 64
 
 
+#define fdclose sysfdclose
 #include <stdio.h>
+#undef fdclose
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
