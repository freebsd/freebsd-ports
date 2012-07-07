--- ./src/cgnstools/utilities/binaryio.h.orig	2011-02-12 23:52:26.000000000 +0100
+++ ./src/cgnstools/utilities/binaryio.h	2012-03-13 22:38:55.000000000 +0100
@@ -98,7 +98,7 @@
 # define MACH_LOCAL     MACH_WIN32
 #endif
 
-#if defined(__linux) || defined(__CYGWIN__)
+#if defined(__linux) || defined(__CYGWIN__) || defined(__FreeBSD__)
 # define ARCH_LOCAL     ARCH_BSIEEE
 # define MACH_LOCAL     MACH_LINUX
 #endif
