--- src/dfxml/src/dfxml_writer.cpp.orig	2014-01-18 09:18:03.000000000 +0900
+++ src/dfxml/src/dfxml_writer.cpp	2014-01-18 09:18:26.000000000 +0900
@@ -657,7 +657,7 @@
 #endif
 
 #ifdef HAVE_AFFLIB_AFFLIB_H
-//#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
+#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
 #include <afflib/afflib.h>
 #endif
 
