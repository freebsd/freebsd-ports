--- libaegisub/include/libaegisub/format.h.orig	2014-12-08 00:07:09 UTC
+++ libaegisub/include/libaegisub/format.h
@@ -19,6 +19,7 @@
 #include <boost/interprocess/streams/vectorstream.hpp>
 #include <boost/io/ios_state.hpp>
 #include <type_traits>
+#include <typeinfo> // std::bad_cast
 
 class wxString;
 
