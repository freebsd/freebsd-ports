--- kkconsui-0.1/src/conscommon.cc.orig	Tue Jul 16 19:18:01 2002
+++ kkconsui-0.1/src/conscommon.cc	Tue Jul 16 19:20:11 2002
@@ -28,6 +28,8 @@
 #include <sys/filio.h>
 #endif
 
+#include <iostream>
+
 bool kintf_graph = true, kintf_refresh = true;
 
 void (*kt_resize_event)(void);
@@ -255,7 +257,7 @@
 #include <fribidi/fribidi.h>
 }
 
-string makebidi(const string &buf, int lpad = 0) {
+string makebidi(const string &buf, int lpad) {
     FriBidiChar *us, *out_us;
     char *outstring, *cbuf;
     int size;
