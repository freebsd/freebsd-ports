--- vdelivermail.c.orig	Sat Nov  2 22:34:39 2002
+++ vdelivermail.c	Sat Nov  2 22:35:20 2002
@@ -263,7 +263,7 @@
 
     /* check for wildcard if there's no match */
     if(tmpstr == NULL) {
-        for(i=strlen(TheUser);i >= 0 && j != 1;--i) {
+        for(i=strlen(TheUser);i > 0 && j != 1;--i) {
             if(TheUser[i-1]=='-') {
                 tmpuser[0] = '\0';
                 strncat(tmpuser,TheUser,i); 
