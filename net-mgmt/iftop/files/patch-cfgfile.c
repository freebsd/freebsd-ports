--- cfgfile.c.orig	Tue Nov 11 22:10:29 2003
+++ cfgfile.c	Tue Nov 11 22:10:43 2003
@@ -8,6 +8,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <sys/types.h>
 
 #include "stringmap.h"
 #include "iftop.h"
