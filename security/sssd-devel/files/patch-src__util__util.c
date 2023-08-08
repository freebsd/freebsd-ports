--- src/util/util.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/util.c
@@ -763,6 +763,16 @@ errno_t sss_fd_nonblocking(int fd)
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
