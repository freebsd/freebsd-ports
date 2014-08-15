--- ./src/library/tools/givtruncdomain.h.orig	2014-08-11 23:06:35.000000000 +0200
+++ ./src/library/tools/givtruncdomain.h	2014-08-11 23:06:42.000000000 +0200
@@ -17,7 +17,7 @@
 #ifdef __APPLE__
 #include <utility>
 #else
-#include <bits/stl_pair.h>
+/* #include <bits/stl_pair.h> */
 #endif
 #endif
 
