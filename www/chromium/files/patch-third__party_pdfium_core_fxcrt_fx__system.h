--- third_party/pdfium/core/fxcrt/fx_system.h.orig	2016-12-13 00:26:52 UTC
+++ third_party/pdfium/core/fxcrt/fx_system.h
@@ -40,7 +40,7 @@
 #elif defined(_WIN64)
 #define _FX_OS_ _FX_WIN64_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_WINDOWS_
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #define _FX_OS_ _FX_LINUX_DESKTOP_
 #define _FXM_PLATFORM_ _FXM_PLATFORM_LINUX_
 #elif defined(__APPLE__)
