--- src/cups/commandtoepson.c.orig	2023-03-05 16:52:54.260430000 +0100
+++ src/cups/commandtoepson.c	2023-03-05 17:46:05.937425000 +0100
@@ -25,12 +25,14 @@
  * Include necessary headers...
  */
 
-#include <cups/cups.h>
+#define __BSD_VISIBLE 1
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include <strings.h>
+#include <sys/types.h>
+#include <cups/cups.h>
 
 /*
  * Macros...
