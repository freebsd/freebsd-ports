--- addons/library.xbmc.addon/libXBMC_addon.h.orig
+++ addons/library.xbmc.addon/libXBMC_addon.h
@@ -41,6 +41,22 @@
 #else
 #define ADDON_HELPER_ARCH       "x86"
 #endif
+#else
+#if defined(__FreeBSD__)         // FreeBSD
+#define ADDON_HELPER_PLATFORM   "freebsd"
+#if defined(__x86_64__)
+#define ADDON_HELPER_ARCH       "x86_64"
+#elif defined(_POWERPC)
+#define ADDON_HELPER_ARCH       "powerpc"
+#elif defined(_POWERPC64)
+#define ADDON_HELPER_ARCH       "powerpc64"
+#elif defined(_ARMEL)
+#define ADDON_HELPER_ARCH       "arm"
+#elif defined(_MIPSEL)
+#define ADDON_HELPER_ARCH       "mipsel"
+#else
+#define ADDON_HELPER_ARCH       "x86"
+#endif
 #else                           // linux
 #define ADDON_HELPER_PLATFORM   "linux"
 #if defined(__x86_64__)
@@ -57,6 +73,7 @@
 #define ADDON_HELPER_ARCH       "i486"
 #endif
 #endif
+#endif
 #include <dlfcn.h>              // linux+osx
 #define ADDON_HELPER_EXT        ".so"
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-" ADDON_HELPER_ARCH "-" ADDON_HELPER_PLATFORM ADDON_HELPER_EXT
