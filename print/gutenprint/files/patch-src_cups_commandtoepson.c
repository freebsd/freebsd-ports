--- src/cups/commandtoepson.c.orig	2024-06-02 23:00:55 UTC
+++ src/cups/commandtoepson.c
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
