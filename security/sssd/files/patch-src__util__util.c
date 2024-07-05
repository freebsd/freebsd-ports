--- src/util/util.c.orig	2020-03-17 13:31:28 UTC
+++ src/util/util.c
@@ -830,6 +830,19 @@ errno_t sss_fd_nonblocking(int fd)
     return EOK;
 }
 
+
+#ifdef __FreeBSD__
+int flb_timezone(void)
+{
+    struct tm tm;
+    time_t t = 0;
+    tzset();
+    localtime_r(&t, &tm);
+    return -(tm.tm_gmtoff);
+}
+#define timezone (flb_timezone())
+#endif
+
 /* Convert GeneralizedTime (http://en.wikipedia.org/wiki/GeneralizedTime)
  * to unix time (seconds since epoch). Use UTC time zone.
  */
