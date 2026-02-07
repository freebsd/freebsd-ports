--- otpw.c.orig	2014-08-07 19:21:15 UTC
+++ otpw.c
@@ -68,7 +68,7 @@ static struct otpw_pwdbuf *otpw_malloc_p
   
   buflen = sysconf(_SC_GETPW_R_SIZE_MAX); /* typical value: 1024 */
   /* fprintf(stderr, "_SC_GETPW_R_SIZE_MAX = %ld\n", buflen); */
-  if (buflen < 0) return NULL;
+  if (buflen < 0) buflen = 1024;
   p = (struct otpw_pwdbuf *) malloc(sizeof(struct otpw_pwdbuf) + buflen);
   if (p) p->buflen = buflen;
   return p;
