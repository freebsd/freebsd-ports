--- kkconsui-0.1/src/conscommon.cc.orig	Tue Aug 20 14:50:35 2002
+++ kkconsui-0.1/src/conscommon.cc	Tue Aug 20 14:51:10 2002
@@ -256,7 +256,7 @@
 #include <fribidi/fribidi.h>
 }
 
-string makebidi(const string &buf, int lpad = 0) {
+string makebidi(const string &buf, int lpad) {
     if(!use_fribidi) return buf;
 
     FriBidiChar *us, *out_us;
