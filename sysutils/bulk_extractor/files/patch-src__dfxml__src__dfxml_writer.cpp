--- src/dfxml/src/dfxml_writer.cpp.orig	2014-09-16 18:34:02 UTC
+++ src/dfxml/src/dfxml_writer.cpp
@@ -646,6 +646,7 @@ void dfxml_writer::xmlout(const string &tag,const stri
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
 #include <exiv2/error.hpp>
+#include <exiv2/exiv2.hpp>
 #endif
 
 #ifdef HAVE_HASHDB
@@ -653,7 +654,7 @@ void dfxml_writer::xmlout(const string &tag,const stri
 #endif
 
 #ifdef HAVE_AFFLIB_AFFLIB_H
-//#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
+#pragma GCC diagnostic ignored "-Wreserved-user-defined-literal"               // required for C11
 #include <afflib/afflib.h>
 #endif
 
