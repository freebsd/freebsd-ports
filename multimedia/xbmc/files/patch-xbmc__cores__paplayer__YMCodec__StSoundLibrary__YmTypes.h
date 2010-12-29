--- ./xbmc/cores/paplayer/YMCodec/StSoundLibrary/YmTypes.h.orig	2008-07-15 20:34:24.000000000 +0200
+++ ./xbmc/cores/paplayer/YMCodec/StSoundLibrary/YmTypes.h	2010-12-01 12:17:34.219682526 +0100
@@ -39,20 +39,20 @@
 // Platform specific stuff
 //-----------------------------------------------------------
 
-#if defined(_WIN32) || defined(__linux__)
+#if defined(_WIN32) || defined(__linux__) || defined(__FreeBSD__)
 
 // These settings are ok for Windows 32bits platform.
 
 #ifdef YM_INTEGER_ONLY
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <inttypes.h>
 typedef 	int64_t				yms64;
-#else
+#else /* !__linux__ */
 typedef		__int64				yms64;
-#endif
-#else
+#endif /* __linux__ */
+#else /* !YM_INTEGER_ONLY */
 typedef		float				ymfloat;
-#endif
+#endif /* YM_INTEGER_ONLY */
 
 typedef		signed char			yms8;			//  8 bits signed integer
 typedef		signed short		yms16;			// 16 bits signed integer
