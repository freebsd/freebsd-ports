--- metamail/codes.c.orig	1993-09-20 22:13:22.000000000 +0900
+++ metamail/codes.c	2012-10-13 07:59:21.000000000 +0900
@@ -13,6 +13,7 @@
 WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES.
 */
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 
@@ -203,7 +204,7 @@
                  && (Buf[0] == '-')
                  && (Buf[1] == '-')
                  && PendingBoundary(Buf, boundaries, boundaryct)) {
-                return;
+                return(0);
             }
             fprintf(stderr, "Ignoring unrecognized boundary line: %s\n", Buf);
             continue;
@@ -221,7 +222,7 @@
         } while (c4 != EOF && isspace(c4));
         if (c2 == EOF || c3 == EOF || c4 == EOF) {
             fprintf(stderr, "Warning: base64 decoder saw premature EOF!\n");
-            return;
+            return(0);
         }
         if (c1 == '=' || c2 == '=') {
             DataDone=1;
@@ -371,7 +372,7 @@
                  && (Buf[0] == '-')
                  && (Buf[1] == '-')
                  && PendingBoundary(Buf, boundaries, boundaryct)) {
-                return;
+                return(0);
             }
             /* Not a boundary, now we must treat THIS line as q-p, sigh */
             if (neednewline) {
