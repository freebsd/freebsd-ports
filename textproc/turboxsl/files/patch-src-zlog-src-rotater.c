--- src/zlog/src/rotater.c.orig	2015-07-10 03:31:33.156849000 +0900
+++ src/zlog/src/rotater.c	2015-07-10 03:31:42.997304000 +0900
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 
+#include <sys/types.h>
 #include <string.h>
 #include <glob.h>
 #include <stdio.h>
