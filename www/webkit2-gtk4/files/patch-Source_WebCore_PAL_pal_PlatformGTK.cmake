Index: Source/WebCore/PAL/pal/PlatformGTK.cmake
--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -20,6 +20,14 @@ list(APPEND PAL_SOURCES
     unix/LoggingUnix.cpp
 )
 
+list(APPEND PAL_INCLUDE_DIRECTORIES
+    ${LIBGCRYPT_INCLUDE_DIRS}
+)
+
+list(APPEND PAL_LIBRARIES
+    ${LIBGCRYPT_LIBRARIES}
+)
+
 if (ENABLE_WEB_CRYPTO)
     list(APPEND PAL_PUBLIC_HEADERS
         crypto/tasn1/Utilities.h
