--- libefont/cff.cc.orig	2015-07-30 17:15:25 UTC
+++ libefont/cff.cc
@@ -27,6 +27,7 @@
 #include <ctype.h>
 #include <efont/t1unparser.hh>
 
+#undef static_assert
 #ifndef static_assert
 #define static_assert(c, msg) switch ((int) (c)) case 0: case (c):
 #endif
