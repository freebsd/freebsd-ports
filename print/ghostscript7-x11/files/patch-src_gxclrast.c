--- src/gxclrast.c.orig	2003-01-17 00:49:03 UTC
+++ src/gxclrast.c
@@ -87,10 +87,10 @@ cmd_print_bits(const byte * data, int wi
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
