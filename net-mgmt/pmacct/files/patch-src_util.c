--- src/util.c.orig	2021-11-05 15:03:23 UTC
+++ src/util.c
@@ -2069,8 +2069,8 @@ void compose_timestamp(char *buf, int buflen, struct t
   if (buflen < VERYSHORTBUFLEN) return; 
 
   if (since_epoch) {
-    if (usec) snprintf(buf, buflen, "%ld.%.6ld", tv->tv_sec, (long)tv->tv_usec);
-    else snprintf(buf, buflen, "%ld", tv->tv_sec);
+    if (usec) snprintf(buf, buflen, "%ld.%.6ld", (long)tv->tv_sec, (long)tv->tv_usec);
+    else snprintf(buf, buflen, "%ld", (long)tv->tv_sec);
   }
   else {
     time1 = tv->tv_sec;
