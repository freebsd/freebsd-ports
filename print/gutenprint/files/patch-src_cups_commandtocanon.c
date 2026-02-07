--- src/cups/commandtocanon.c.orig	2023-03-05 17:47:41.520731000 +0100
+++ src/cups/commandtocanon.c	2023-03-05 17:48:26.896443000 +0100
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
