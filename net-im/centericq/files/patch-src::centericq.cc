
$FreeBSD$

--- src/centericq.cc	2002/11/21 14:55:51	1.1
+++ src/centericq.cc	2002/11/21 14:56:12
@@ -1460,8 +1460,8 @@
     unsigned char *table = 0;
 
 #ifdef HAVE_ICONV_H
-    if(tdir == "kw") r = siconv(text, "koi8-r", "cp1251"); else
-    if(tdir == "wk") r = siconv(text, "cp1251", "koi8-r"); else
+    if(tdir == "kw") r = siconv(text, "koi8-u", "cp1251"); else
+    if(tdir == "wk") r = siconv(text, "cp1251", "koi8-u"); else
 #endif
 	r = text;
 
