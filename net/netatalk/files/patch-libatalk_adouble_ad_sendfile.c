--- libatalk/adouble/ad_sendfile.c.orig	2011-12-05 13:28:30.000000000 +0000
+++ libatalk/adouble/ad_sendfile.c	2012-04-29 00:47:10.375795000 +0000
@@ -67,7 +67,16 @@ ssize_t sys_sendfile(int tofd, int fromf
 #include <sys/uio.h>
 ssize_t sys_sendfile(int tofd, int fromfd, off_t *offset, size_t count)
 {
-  return sendfile(fromfd, tofd, *offset, count, NULL, offset, 0);
+    off_t len;
+    int ret;
+
+    ret = sendfile(fromfd, tofd, *offset, count, NULL, &len, 0);
+
+    *offset += len;
+
+    if (ret != 0)
+        return -1;
+    return len;
 }
 
 #else
