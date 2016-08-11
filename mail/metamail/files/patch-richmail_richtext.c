--- richmail/richtext.c.orig	1994-02-09 16:31:18 UTC
+++ richmail/richtext.c
@@ -14,6 +14,8 @@ WITHOUT ANY EXPRESS OR IMPLIED WARRANTIE
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <signal.h>
 #include "richlex.h"
@@ -155,6 +157,16 @@ static nomemabort() {
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
 
@@ -910,7 +922,7 @@ struct charsetmember *s;
 FILE *fp;
 {
     int inmargin=1;
-    if (!s) return;
+    if (!s) return(0);
     while (s -> ch) {
         if (inmargin && (s -> ch) == ' ') {
             controloutput(MoveRight, 1);
@@ -932,7 +944,7 @@ char *standoutbuf, *standendbuf, *StartU
     *BoldOn, *BoldOff;
 {
     if (OverStrike)
-	return;
+	return(0);
 
     /* We always turn back on the appropriate terminal modes, because
       on some terminals one thing turns off all of them */
@@ -989,16 +1001,6 @@ FILE *fp;
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
