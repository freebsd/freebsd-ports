--- xorg-server-X11R7.1-1.1.0/hw/xfree86/common/compiler.h.orig	2013-12-19 04:09:03.884558740 +0000
+++ xorg-server-X11R7.1-1.1.0/hw/xfree86/common/compiler.h	2013-12-19 04:10:29.576270046 +0000
@@ -1364,7 +1364,7 @@
 
 #    if !defined(__SUNPRO_C)
 #    if !defined(FAKEIT) && !defined(__mc68000__) && !defined(__arm__) && !defined(__sh__) && !defined(__hppa__)
-#     ifdef GCCUSESGAS
+#     ifdef __GNUC__
 
 /*
  * If gcc uses gas rather than the native assembler, the syntax of these
