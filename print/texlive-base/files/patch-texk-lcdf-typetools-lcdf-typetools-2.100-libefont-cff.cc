--- texk/lcdf-typetools/lcdf-typetools-2.100/libefont/cff.cc.orig	2014-01-09 21:51:50.000000000 +0900
+++ texk/lcdf-typetools/lcdf-typetools-2.100/libefont/cff.cc	2014-08-20 23:34:37.000000000 +0900
@@ -27,6 +27,7 @@
 #include <ctype.h>
 #include <efont/t1unparser.hh>
 
+#undef static_assert
 #ifndef static_assert
 #define static_assert(c, msg) switch (c) case 0: case (c):
 #endif
