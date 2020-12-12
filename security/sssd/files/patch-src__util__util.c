--- src/util/util.c	2020-10-20 19:31:51.466783000 +0100
+++ src/util/util.c	2020-10-20 19:33:20.832098000 +0100
@@ -830,6 +830,19 @@
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
