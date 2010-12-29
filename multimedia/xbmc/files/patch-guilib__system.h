--- ./guilib/system.h.orig	2010-11-09 20:05:35.000000000 +0100
+++ ./guilib/system.h	2010-12-01 12:17:34.292155875 +0100
@@ -66,7 +66,9 @@
 #define HAS_FILESYSTEM_SAP
 #define HAS_FILESYSTEM_VTP
 #define HAS_FILESYSTEM_HTSP
+#ifdef HAVE_LIBMMS
 #define HAS_FILESYSTEM_MMS
+#endif
 
 /**********************
  * Non-free Components
@@ -134,7 +136,9 @@
 #define HAS_GLX
 #define HAS_LINUX_NETWORK
 #define HAS_SDL_AUDIO
+#if !defined(__FreeBSD__)
 #define HAS_LIRC
+#endif
 #define HAS_SDL_WIN_EVENTS
 #ifdef HAVE_LIBPULSE
 #define HAS_PULSEAUDIO
