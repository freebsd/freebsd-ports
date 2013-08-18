--- xbmc/libXBMC_addon.h.orig	2013-07-09 11:52:01.000000000 +0200
+++ xbmc/libXBMC_addon.h	2013-08-08 00:32:27.455183557 +0200
@@ -42,6 +42,16 @@
 #else
 #define ADDON_HELPER_ARCH       "x86-osx"
 #endif
+#elif defined(__FreeBSD__)	// freebsd
+#if defined(__x86_64__)
+#define ADDON_HELPER_ARCH	"x86_64-freebsd"
+#elif defined(_POWERPC)
+#define ADDON_HELPER_ARCH	"powerpc-freebsd"
+#elif defined(_POWERPC64)
+#define ADDON_HELPER_ARCH	"powerpc64-freebsd"
+#else
+#define ADDON_HELPER_ARCH	"i386-freebsd"
+#endif
 #else                           // linux
 #if defined(__x86_64__)
 #define ADDON_HELPER_ARCH       "x86_64-linux"
