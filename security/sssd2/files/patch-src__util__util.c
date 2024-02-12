--- src/util/util.c.orig	2024-01-12 12:05:40 UTC
+++ src/util/util.c
@@ -786,6 +786,16 @@ errno_t sss_fd_nonblocking(int fd)
     return EOK;
 }
 
+int flb_timezone(void)
+{
+    struct tm tm;
+    time_t t = 0;
+    tzset();
+    localtime_r(&t, &tm);
+    return -(tm.tm_gmtoff);
+}
+#define timezone (flb_timezone())
+
 /* Convert GeneralizedTime (http://en.wikipedia.org/wiki/GeneralizedTime)
  * to unix time (seconds since epoch). Use UTC time zone.
  */
