--- addons/library.xbmc.gui/libXBMC_gui.h.orig
+++ addons/library.xbmc.gui/libXBMC_gui.h
@@ -44,13 +44,29 @@ typedef void* GUIHANDLE;
 #elif defined(_ARMEL)
 #define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-arm.so"
 #elif defined(__x86_64__)
+#ifdef __FreeBSD__
+#define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-x86_64-freebsd.so"
+#else
 #define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-x86_64-linux.so"
+#endif
 #elif defined(_POWERPC)
+#ifdef __FreeBSD__
+#define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-powerpc-freebsd.so"
+#else
 #define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-powerpc-linux.so"
+#endif
 #elif defined(_POWERPC64)
+#ifdef __FreeBSD__
+#define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-powerpc64-freebsd.so"
+#else
 #define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-powerpc64-linux.so"
+#endif
 #else /* !__x86_64__ && !__powerpc__ && !_ARMEL */
+#ifdef __FreeBSD__
+#define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-i386-freebsd.so"
+#else
 #define GUI_HELPER_DLL "/library.xbmc.gui/libXBMC_gui-i486-linux.so"
+#endif
 #endif /* __x86_64__ */
 #endif /* _LINUX */
 
