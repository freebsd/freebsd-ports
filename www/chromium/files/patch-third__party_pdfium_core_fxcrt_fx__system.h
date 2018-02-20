--- third_party/pdfium/core/fxcrt/fx_system.h.orig	2017-12-15 02:05:39.000000000 +0100
+++ third_party/pdfium/core/fxcrt/fx_system.h	2017-12-24 18:45:42.922884000 +0100
@@ -40,7 +40,7 @@
 #elif defined(_WIN64)
 #define _FX_OS_ _FX_OS_WIN64_
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define _FX_OS_ _FX_OS_LINUX_
 #define _FX_PLATFORM_ _FX_PLATFORM_LINUX_
 #elif defined(__APPLE__)
