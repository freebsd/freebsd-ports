-- Fix loopback interface detection on FreeBSD and other BSDs.
-- The upstream code only checks for __APPLE__ or the BSD macro, which is not
-- defined by default on FreeBSD. preCICE uses "lo0" on BSD systems.
-- Upstream issue: https://github.com/precice/precice/issues/2278
--- src/utils/networking.cpp.orig	2026-08-04 00:41:46 UTC
+++ src/utils/networking.cpp
@@ -6,7 +6,7 @@ std::string loopbackInterfaceName()
 {
 #if defined(__linux__)
   return "lo";
-#elif defined(__APPLE__) || defined(BSD)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
   return "lo0";
 #elif defined(_WIN32)
   // Not required as we directly use the 127.0.0.1 under Windows
