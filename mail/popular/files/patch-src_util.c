--- src/util.c.orig	2001-04-30 15:14:14 UTC
+++ src/util.c
@@ -125,7 +125,7 @@ timedesc2sec(char *desc, int min, int max)
   while (1) {
     if (*tptr == '-') return -1;
     value = strtol(tptr, &tptr, 10);
-    if (errno) return -1;
+    if (errno && errno != EINVAL) return -1;
     switch (*tptr) {
       case 'd':
     	sec += value*60*60*24;
