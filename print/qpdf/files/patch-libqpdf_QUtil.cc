Workaround for https://github.com/qpdf/qpdf/issues/177

--- libqpdf/QUtil.cc.orig	2018-01-29 18:08:43 UTC
+++ libqpdf/QUtil.cc
@@ -354,7 +354,7 @@ void
 QUtil::setLineBuf(FILE* f)
 {
 #ifndef _WIN32
-    setvbuf(f, reinterpret_cast<char *>(NULL), _IOLBF, 0);
+    setvbuf(f, reinterpret_cast<char *>(0), _IOLBF, 0);
 #endif
 }
 
