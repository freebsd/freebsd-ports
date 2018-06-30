--- xbmc/addons/kodi-addon-dev-kit/include/kodi/libXBMC_addon.h.orig	2017-11-14 17:55:01.000000000 +0100
+++ xbmc/addons/kodi-addon-dev-kit/include/kodi/libXBMC_addon.h	2018-04-27 14:28:13.572553000 +0200
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <stdint.h>
 #include <stdarg.h>
+#include <sys/param.h>
 
 #if defined(BUILD_KODI_ADDON)
 #include "IFileTypes.h"
@@ -66,6 +67,17 @@
 #define ADDON_HELPER_ARCH       "x86-osx"
 #endif
 #define ADDON_HELPER_EXT        ".dylib"
+#elif defined(__FreeBSD__)	// freebsd
+#if defined(__x86_64__)
+#define ADDON_HELPER_ARCH       "x86_64-freebsd"
+#elif defined(__ARMEL__)
+#define ADDON_HELPER_ARCH       "arm"
+#elif defined(__aarch64__)
+#define ADDON_HELPER_ARCH       "aarch64"
+#else
+#define ADDON_HELPER_ARCH       "i486-freebsd"
+#endif
+#define ADDON_HELPER_EXT        ".so"
 #else                           // linux
 #if defined(__x86_64__)
 #define ADDON_HELPER_ARCH       "x86_64-linux"
