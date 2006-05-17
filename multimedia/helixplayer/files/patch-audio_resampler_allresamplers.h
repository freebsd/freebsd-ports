--- ./audio/resampler/allresamplers.h.orig	Fri Jul  9 04:01:17 2004
+++ ./audio/resampler/allresamplers.h	Sun Aug 15 22:07:50 2004
@@ -125,7 +125,7 @@
 
 #ifndef _AIX
 typedef unsigned char uchar;
-#if !defined(_HPUX) && !defined(_LINUX) && !defined(_MAC_MACHO)
+#if !defined(_HPUX) && !defined(_LINUX) && !defined(_MAC_MACHO) && !defined(_FREEBSD4)
 typedef unsigned int uint;
 #endif
 #endif
