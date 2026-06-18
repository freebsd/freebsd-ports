--- src/cups/commandtocanon.c.orig	2024-06-02 23:00:55 UTC
+++ src/cups/commandtocanon.c
@@ -11,11 +11,13 @@
  * Include necessary headers...
  */
 
-#include <cups/cups.h>
+#define __BSD_VISIBLE 1
 #include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <strings.h>
+#include <sys/types.h>
+#include <cups/cups.h>
 
 
 /*
