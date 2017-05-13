--- Source/WebCore/PAL/pal/PlatformGTK.cmake.orig	2017-04-17 15:36:57.688080000 +0200
+++ Source/WebCore/PAL/pal/PlatformGTK.cmake	2017-04-17 15:39:47.928689000 +0200
@@ -1,3 +1,11 @@
 list(APPEND PAL_SOURCES
     crypto/gcrypt/CryptoDigestGCrypt.cpp
 )
+
+list(APPEND PAL_INCLUDE_DIRECTORIES
+    ${LIBGCRYPT_INCLUDE_DIRS}
+)
+list(APPEND PAL_LIBRARIES
+    ${LIBGCRYPT_LIBRARIES}
+)
+
