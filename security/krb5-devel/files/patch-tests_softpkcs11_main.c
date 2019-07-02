--- tests/softpkcs11/main.c.orig	2019-07-01 17:36:37.000000000 -0700
+++ tests/softpkcs11/main.c	2019-07-02 14:13:26.478468000 -0700
@@ -179,6 +179,7 @@
 {
     int len;
     va_list ap;
+    va_start(ap, fmt);
     len = vsnprintf(str, size, fmt, ap);
     va_end(ap);
     if (len < 0 || len > size)
