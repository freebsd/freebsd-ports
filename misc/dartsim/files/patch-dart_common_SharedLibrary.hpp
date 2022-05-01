--- dart/common/SharedLibrary.hpp.orig	2021-11-04 20:43:53 UTC
+++ dart/common/SharedLibrary.hpp
@@ -41,7 +41,7 @@
 #include "dart/common/Deprecated.hpp"
 #include "dart/common/Platform.hpp"
 
-#if DART_OS_LINUX
+#if DART_OS_LINUX || DART_OS_FREEBSD
 
   #define DYNLIB_HANDLE void*
 
@@ -65,6 +65,8 @@ using hInstance = HINSTANCE__*;
 
 #if DART_OS_LINUX
 static constexpr const char* DART_SHARED_LIB_EXTENSION = "so";
+#elif DART_OS_FREEBSD
+static constexpr const char* DART_SHARED_LIB_EXTENSION = "so";
 #elif DART_OS_MACOS
 static constexpr const char* DART_SHARED_LIB_EXTENSION = "dylib";
 #elif DART_OS_WINDOWS
@@ -74,6 +76,8 @@ static constexpr const char* DART_SHARED_LIB_EXTENSION
 #endif
 
 #if DART_OS_LINUX
+static constexpr const char* DART_SHARED_LIB_PREFIX = "lib";
+#elif DART_OS_FREEBSD
 static constexpr const char* DART_SHARED_LIB_PREFIX = "lib";
 #elif DART_OS_MACOS
 static constexpr const char* DART_SHARED_LIB_PREFIX = "lib";
