--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2018-02-19 07:45:31 UTC
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake
@@ -12,6 +12,13 @@ list(APPEND PAL_SOURCES
     unix/LoggingUnix.cpp
 )
 
+list(APPEND PAL_INCLUDE_DIRECTORIES
+    ${LIBGCRYPT_INCLUDE_DIRS}
+)
+list(APPEND PAL_LIBRARIES
+    ${LIBGCRYPT_LIBRARIES}
+)
+
 if (ENABLE_SUBTLE_CRYPTO)
     list(APPEND PAL_SOURCES
         crypto/tasn1/Utilities.cpp
