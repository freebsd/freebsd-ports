--- dart/common/SharedLibrary.hpp.orig	2018-11-20 05:50:43 UTC
+++ dart/common/SharedLibrary.hpp
@@ -38,7 +38,7 @@
 #include <boost/filesystem.hpp>
 #include "dart/common/Platform.hpp"
 
-#if DART_OS_LINUX
+#if DART_OS_LINUX || DART_OS_FREEBSD
 
 #define DYNLIB_HANDLE void*
 
