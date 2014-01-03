--- ./libefont/cff.cc.orig	2013-08-13 20:22:52.000000000 +0000
+++ ./libefont/cff.cc	2014-01-03 11:41:17.000000000 +0000
@@ -27,6 +27,7 @@
 #include <ctype.h>
 #include <efont/t1unparser.hh>
 
+#undef static_assert
 #ifndef static_assert
 #define static_assert(c) switch (c) case 0: case (c):
 #endif
