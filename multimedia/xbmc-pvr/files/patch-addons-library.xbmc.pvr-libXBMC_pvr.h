--- addons/library.xbmc.pvr/libXBMC_pvr.h.orig
+++ addons/library.xbmc.pvr/libXBMC_pvr.h
@@ -41,15 +41,31 @@
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-x86-osx.so"
 #endif
 #elif defined(__x86_64__)
+#ifdef __FreeBSD__
+#define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-x86_64-freebsd.so"
+#else
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-x86_64-linux.so"
+#endif
 #elif defined(_POWERPC)
+#ifdef __FreeBSD__
+#define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-powerpc-freebsd.so"
+#else
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-powerpc-linux.so"
+#endif
 #elif defined(_POWERPC64)
+#ifdef __FreeBSD__
+#define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-powerpc64-freebsd.so"
+#else
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-powerpc64-linux.so"
+#endif
 #elif defined(_ARMEL)
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-arm.so"
 #else /* !__x86_64__ && !__powerpc__ */
+#ifdef __FreeBSD__
+#define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-i386-freebsd.so"
+#else
 #define PVR_HELPER_DLL "/library.xbmc.pvr/libXBMC_pvr-i486-linux.so"
+#endif
 #endif /* __x86_64__ */
 #endif /* _LINUX */
 
