--- maint/histinfo.c.orig	1995-01-02 22:48:43.000000000 +0100
+++ maint/histinfo.c	2011-05-12 15:36:35.000000000 +0200
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>		/* for modified time (date received) */
 #include <string.h>
