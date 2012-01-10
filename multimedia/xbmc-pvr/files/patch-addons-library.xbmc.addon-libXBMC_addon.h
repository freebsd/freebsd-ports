--- addons/library.xbmc.addon/libXBMC_addon.h.orig
+++ addons/library.xbmc.addon/libXBMC_addon.h
@@ -40,15 +40,31 @@
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-x86-osx.so"
 #endif
 #elif defined(__x86_64__)
+#ifdef __FreeBSD__
+#define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-x86_64-freebsd.so"
+#else
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-x86_64-linux.so"
+#endif
 #elif defined(_POWERPC)
+#ifdef __FreeBSD__
+#define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-powerpc-freebsd.so"
+#else
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-powerpc-linux.so"
+#endif
 #elif defined(_POWERPC64)
+#ifdef __FreeBSD__
+#define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-powerpc64-freebsd.so"
+#else
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-powerpc64-linux.so"
+#endif
 #elif defined(_ARMEL)
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-arm.so"
 #else /* !__x86_64__ && !__powerpc__ */
+#ifdef __FreeBSD__
+#define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-x86-freebsd.so"
+#else
 #define ADDON_DLL "/library.xbmc.addon/libXBMC_addon-i486-linux.so"
+#endif
 #endif /* __x86_64__ */
 #endif /* _LINUX */
 
