Apache issue: https://issues.apache.org/bugzilla/show_bug.cgi?id=52900

Obtained from:
http://svn.apache.org/viewvc?view=revision&revision=1470183
============================================================
--- ./server/core.c.orig	2013-02-06 18:15:16.000000000 +0100
+++ ./server/core.c	2013-04-20 19:11:17.000000000 +0200
@@ -4768,13 +4768,18 @@
 AP_DECLARE(apr_uint32_t) ap_random_pick(apr_uint32_t min, apr_uint32_t max)
 {
     apr_uint32_t number;
+#if (!__GNUC__ || __GNUC__ >= 5 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8) || \
+     !__sparc__ || APR_SIZEOF_VOIDP != 8)
+    /* This triggers a gcc bug on sparc/64bit with gcc < 4.8, PR 52900 */
     if (max < 16384) {
         apr_uint16_t num16;
         ap_random_insecure_bytes(&num16, sizeof(num16));
         RAND_RANGE(num16, min, max, APR_UINT16_MAX);
         number = num16;
     }
-    else {
+    else
+#endif
+    {
         ap_random_insecure_bytes(&number, sizeof(number));
         RAND_RANGE(number, min, max, APR_UINT32_MAX);
     }
