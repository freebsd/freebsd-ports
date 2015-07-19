--- texk/lcdf-typetools/lcdf-typetools-2.104/libefont/cff.cc.orig	2014-07-08 06:44:39 UTC
+++ texk/lcdf-typetools/lcdf-typetools-2.104/libefont/cff.cc
@@ -27,6 +27,7 @@
 #include <ctype.h>
 #include <efont/t1unparser.hh>
 
+#undef static_assert
 #ifndef static_assert
 #define static_assert(c, msg) switch ((int) (c)) case 0: case (c):
 #endif
