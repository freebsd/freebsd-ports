--- util.c.orig	2026-08-27 12:38:15 UTC
+++ util.c
@@ -790,7 +790,7 @@ UTI_TimespecToNtp64(const struct timespec *src, NTP_in
     hi = lo = 0;
   } else {
     hi = htonl(sec + JAN_1970);
-    lo = htonl(NSEC_PER_NTP64 * nsec);
+    lo = htonl((uint32_t)(NSEC_PER_NTP64 * nsec));
 
     /* Add the fuzz */
     if (fuzz) {
