--- ./third_party/pdfium/core/include/fxcrt/fx_system.h.orig	2014-08-20 21:03:59.000000000 +0200
+++ ./third_party/pdfium/core/include/fxcrt/fx_system.h	2014-08-22 15:13:48.000000000 +0200
@@ -21,7 +21,7 @@
 #elif defined(_WIN32) || defined(_WIN64)
 #define _FX_OS_ _FX_WIN32_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define _FX_OS_ _FX_LINUX_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_LINUX_
 #elif defined(__APPLE__)
