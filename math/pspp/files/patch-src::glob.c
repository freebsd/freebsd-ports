--- src/glob.c.orig	Mon Dec 23 04:32:08 2002
+++ src/glob.c	Mon Dec 23 04:32:19 2002
@@ -20,6 +20,7 @@
 #include <config.h>
 
 #include <assert.h>
+#include <stdio.h>
 #include <stdlib.h>
 
 #if TIME_WITH_SYS_TIME
