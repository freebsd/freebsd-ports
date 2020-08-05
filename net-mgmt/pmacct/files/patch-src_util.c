--- src/util.c.orig	2020-05-10 13:57:54 UTC
+++ src/util.c
@@ -1594,7 +1594,7 @@ void *pm_malloc(size_t size)
 
   obj = (unsigned char *) malloc(size);
   if (!obj) {
-    Log(LOG_ERR, "ERROR ( %s/%s ): Unable to grab enough memory (requested: %lu bytes). Exiting ...\n",
+    Log(LOG_ERR, "ERROR ( %s/%s ): Unable to grab enough memory (requested: %zu bytes). Exiting ...\n",
     config.name, config.type, size);
     exit_gracefully(1);
   }
@@ -2010,8 +2010,8 @@ void compose_timestamp(char *buf, int buflen, struct t
   if (buflen < VERYSHORTBUFLEN) return; 
 
   if (since_epoch) {
-    if (usec) snprintf(buf, buflen, "%ld.%.6ld", tv->tv_sec, (long)tv->tv_usec);
-    else snprintf(buf, buflen, "%ld", tv->tv_sec);
+    if (usec) snprintf(buf, buflen, "%ld.%.6ld", (long)tv->tv_sec, (long)tv->tv_usec);
+    else snprintf(buf, buflen, "%ld", (long)tv->tv_sec);
   }
   else {
     time1 = tv->tv_sec;
