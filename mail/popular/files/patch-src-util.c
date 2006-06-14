--- src/util.c.orig	Mon Apr 30 17:14:14 2001
+++ src/util.c	Wed Jun  7 13:19:59 2006
@@ -125,7 +125,7 @@
   while (1) {
     if (*tptr == '-') return -1;
     value = strtol(tptr, &tptr, 10);
-    if (errno) return -1;
+    if (errno && errno != EINVAL) return -1;
     switch (*tptr) {
       case 'd':
     	sec += value*60*60*24;
