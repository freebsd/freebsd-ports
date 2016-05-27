--- metamail/codes.c.orig	1993-09-20 13:13:22 UTC
+++ metamail/codes.c
@@ -13,6 +13,7 @@ OF THIS MATERIAL FOR ANY PURPOSE.  IT IS
 WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES.
 */
 #include <stdio.h>
+#include <string.h>
 #include <ctype.h>
 #include <config.h>
 
@@ -203,7 +204,7 @@ int PortableNewlines;
                  && (Buf[0] == '-')
                  && (Buf[1] == '-')
                  && PendingBoundary(Buf, boundaries, boundaryct)) {
-                return;
+                return(0);
             }
             fprintf(stderr, "Ignoring unrecognized boundary line: %s\n", Buf);
             continue;
@@ -221,7 +222,7 @@ int PortableNewlines;
         } while (c4 != EOF && isspace(c4));
         if (c2 == EOF || c3 == EOF || c4 == EOF) {
             fprintf(stderr, "Warning: base64 decoder saw premature EOF!\n");
-            return;
+            return(0);
         }
         if (c1 == '=' || c2 == '=') {
             DataDone=1;
@@ -371,7 +372,7 @@ int *boundaryct;
                  && (Buf[0] == '-')
                  && (Buf[1] == '-')
                  && PendingBoundary(Buf, boundaries, boundaryct)) {
-                return;
+                return(0);
             }
             /* Not a boundary, now we must treat THIS line as q-p, sigh */
             if (neednewline) {
