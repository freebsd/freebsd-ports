--- src/gdome_cpp_smart/basic/GdomeSmartDOMGdomeString.cc.orig	Wed Apr  2 12:36:39 2003
+++ src/gdome_cpp_smart/basic/GdomeSmartDOMGdomeString.cc	Wed Apr  2 12:37:21 2003
@@ -95,7 +95,7 @@
 
     while (inBytesLeft > 0) {
       //cout << "before: " << (void*) inbuf << " " << inBytesLeft << " " << (void*) outbuf << " " << outBytesLeft << endl;
-      size_t iconv_res = iconv(cd, &inbuf, &inBytesLeft, &outbuf, &outBytesLeft);
+      size_t iconv_res = iconv(cd, (const char**)&inbuf, &inBytesLeft, &outbuf, &outBytesLeft);
       //cout << "after: " << (void*) inbuf << " " << inBytesLeft << " " << (void*) outbuf << " " << outBytesLeft << endl;
 
       unsigned n = outbuf - outbuf0;
