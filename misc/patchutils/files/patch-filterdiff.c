--- filterdiff.c.orig	Mon Jul 23 17:52:37 2001
+++ filterdiff.c	Mon Jul 23 17:52:53 2001
@@ -22,6 +22,7 @@
 #include "config.h"
 #endif
 
+#include <sys/types.h>
 #include <fnmatch.h>
 #include <stdio.h>
 #include <stdlib.h>
