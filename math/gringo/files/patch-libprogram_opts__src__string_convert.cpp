--- ./libprogram_opts/src/string_convert.cpp.orig	2014-08-12 17:47:21.000000000 +0200
+++ ./libprogram_opts/src/string_convert.cpp	2014-08-21 22:39:08.000000000 +0200
@@ -28,6 +28,9 @@
 }
 #endif
 #endif
+namespace std {
+	using ::strtoull;
+}
 namespace bk_lib { 
 
 static int detectBase(const char* x) {
