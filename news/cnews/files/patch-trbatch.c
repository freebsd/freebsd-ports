--- explode/trbatch.c.orig	1994-11-30 23:09:10.000000000 +0100
+++ explode/trbatch.c	2011-05-12 15:45:54.000000000 +0200
@@ -2,6 +2,7 @@
  * transmit batch file management (exploder version)
  */
 #include <stdio.h>
+#include <string.h>
 #include <errno.h>
 #include "fixerrno.h"
 #include <sys/types.h>
