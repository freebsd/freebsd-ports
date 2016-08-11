--- src/gxclrast.c.orig	2013-04-30 09:13:13.000000000 +0900
+++ src/gxclrast.c	2013-04-30 09:13:41.000000000 +0900
@@ -87,10 +87,10 @@
 private long
 cmd_get_w(const byte * p, const byte ** rp)
 {
-    long val = *p++ & 0x7f;
+    int val = *p++ & 0x7f;
     int shift = 7;
 
-    for (; val += (long)(*p & 0x7f) << shift, *p++ > 0x7f; shift += 7);
+    for (; val += (int)(*p & 0x7f) << shift, *p++ > 0x7f; shift += 7);
     *rp = p;
     return val;
 }
