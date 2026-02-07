--- src/cgnstools/utilities/binaryio.h.orig	2017-07-17 21:51:06 UTC
+++ src/cgnstools/utilities/binaryio.h
@@ -98,7 +98,7 @@
 # define MACH_LOCAL     MACH_WIN32
 #endif
 
-#if defined(__linux) || defined(__CYGWIN__)
+#if defined(__linux) || defined(__CYGWIN__) || defined(__FreeBSD__)
 # define ARCH_LOCAL     ARCH_BSIEEE
 # define MACH_LOCAL     MACH_LINUX
 #endif
