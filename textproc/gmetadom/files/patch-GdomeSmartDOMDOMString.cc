--- src/gdome_cpp_smart/basic/GdomeSmartDOMDOMString.cc.orig	Wed Jul 10 13:37:44 2002
+++ src/gdome_cpp_smart/basic/GdomeSmartDOMDOMString.cc	Wed Jul 10 13:38:17 2002
@@ -83,7 +83,7 @@
 
   while (inBytesLeft > 0) {
     //cout << "before: " << (void*) inbuf << " " << inBytesLeft << " " << (void*) outbuf << " " << outBytesLeft << endl;
-    size_t iconv_res = iconv(cd, &inbuf, &inBytesLeft, &outbuf, &outBytesLeft);
+    size_t iconv_res = iconv(cd, (const char**)&inbuf, &inBytesLeft, &outbuf, &outBytesLeft);
     //cout << "after: " << (void*) inbuf << " " << inBytesLeft << " " << (void*) outbuf << " " << outBytesLeft << endl;
 
     unsigned n = outbuf - outbuf0;
