--- src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.h.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/pdfium/core/fxcrt/fx_system.h
@@ -41,7 +41,7 @@
 #elif defined(_WIN64)
 #define _FX_OS_ _FX_OS_WIN64_
 #define _FX_PLATFORM_ _FX_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define _FX_OS_ _FX_OS_LINUX_
 #define _FX_PLATFORM_ _FX_PLATFORM_LINUX_
 #elif defined(__APPLE__)
