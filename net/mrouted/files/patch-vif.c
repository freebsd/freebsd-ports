--- vif.c.orig	2012-11-30 23:59:58.000000000 +0900
+++ vif.c	2012-12-01 00:02:20.000000000 +0900
@@ -1051,6 +1051,7 @@
 static int info_version(u_char *p)
 {
     int len;
+    size_t lenv;
 
     *p++ = DVMRP_INFO_VERSION;
     p++;	/* skip over length */
@@ -1062,7 +1063,9 @@
      *      as long as 100 bytes, but it's better to limit the amount
      *      of data copied to send_buf since we do not want to risk
      *      sending MAX size frames. */
-    len = strlcpy((char *)p, versionstring, sizeof(versionstring));
+    /* XXX: use lenv to make clang happy. */ 
+    lenv = sizeof(versionstring);
+    len = strlcpy((char *)p, versionstring, lenv);
 
     return ((len + 3) / 4);
 }
