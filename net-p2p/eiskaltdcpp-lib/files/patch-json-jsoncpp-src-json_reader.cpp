--- json/jsoncpp/src/json_reader.cpp.orig	2016-10-04 15:50:44.453094000 +0000
+++ json/jsoncpp/src/json_reader.cpp	2016-10-04 15:48:27.416705000 +0000
@@ -14,6 +14,7 @@
 #include <cassert>
 #include <cstring>
+#include <istream>
 #include <stdexcept>
 
 #if defined(_MSC_VER)  &&  _MSC_VER >= 1400 // VC++ 8.0
 #pragma warning( disable : 4996 )   // disable warning about strdup being deprecated.
