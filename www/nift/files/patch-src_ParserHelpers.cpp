--- src/ParserHelpers.cpp.orig	2026-10-20 14:38:14 UTC
+++ src/ParserHelpers.cpp
@@ -28,7 +28,7 @@
 #elif defined(__linux__)
 #include <cerrno>
 #include <sys/random.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 #include <cstdlib>
 #else
 #error "secure_random_bytes requires a supported native CSPRNG"
@@ -173,7 +173,7 @@ bool nift_secure_random_bytes(std::size_t count, nift:
         error = "secure_random_bytes: operating-system random source failed";
         return false;
     }
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
     if (count != 0) ::arc4random_buf(bytes.data(), bytes.size());
 #endif
     try {
