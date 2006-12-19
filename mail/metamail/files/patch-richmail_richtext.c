--- richmail/richtext.c.orig	Wed Feb  9 17:31:18 1994
+++ richmail/richtext.c	Mon Dec 18 11:46:22 2006
@@ -14,6 +14,8 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <signal.h>
 #include "richlex.h"
@@ -155,6 +157,16 @@
     exit(-1);
 #endif
 }
+static lc2strcmp(s1, s2)
+char *s1, *s2;
+{
+    if (!s1 || !s2) return (-1);
+    while (*s1 && *s2) {
+	if (*s1 != *s2 && (tolower(*s1) != *s2)) return(-1);
+	++s1; ++s2;
+    }
+    return((*s1 == *s2) ? 0 : -1);
+}
 
 #ifndef	RICHTEXT_LIBRARY
 
@@ -989,16 +1001,6 @@
     while(*s) (*RichtextPutc)((int)(*s++),fp);
 }
 
-static lc2strcmp(s1, s2)
-char *s1, *s2;
-{
-    if (!s1 || !s2) return (-1);
-    while (*s1 && *s2) {
-	if (*s1 != *s2 && (tolower(*s1) != *s2)) return(-1);
-	++s1; ++s2;
-    }
-    return((*s1 == *s2) ? 0 : -1);
-}
 
 static lc2strncmp(s1, s2, len)
 char *s1, *s2;
