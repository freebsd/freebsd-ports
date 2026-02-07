--- util.c.orig	2017-01-31 10:22:11 UTC
+++ util.c
@@ -738,7 +738,7 @@ UTI_TimespecToNtp64(struct timespec *src
     hi = lo = 0;
   } else {
     hi = htonl(sec + JAN_1970);
-    lo = htonl(NSEC_PER_NTP64 * nsec);
+    lo = htonl((uint32_t)(NSEC_PER_NTP64 * nsec));
 
     /* Add the fuzz */
     if (fuzz) {
