--- ./src/engine/encoding.cpp.orig	2013-07-30 16:44:46.000000000 +0200
+++ ./src/engine/encoding.cpp	2013-07-30 16:46:02.000000000 +0200
@@ -278,7 +278,7 @@
             errno = 0;
             iconv((iconv_t)(cd -> physCD), 
 #               ifdef SABLOT_ICONV_CAST_OK
-                    (char**)(&inbuf),
+                    (const char**)(&inbuf),
 #               else
                     &inbuf,
 #               endif
