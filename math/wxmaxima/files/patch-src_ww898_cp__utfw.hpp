--- src/ww898/cp_utfw.hpp.orig	2021-05-16 15:23:46 UTC
+++ src/ww898/cp_utfw.hpp
@@ -33,7 +33,7 @@ namespace utf {
 using utfw = utf16;
 }}
 
-#elif defined(__linux__) || defined(__APPLE__) || defined (__NetBSD__)
+#elif defined(__linux__) || defined(__APPLE__) || defined (__NetBSD__) || defined (__FreeBSD__)
 
 #include <ww898/cp_utf32.hpp>
 
