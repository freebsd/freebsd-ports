--- ./src/include/cdfdist.h.orig	Mon Jul 11 23:50:59 2005
+++ ./src/include/cdfdist.h	Fri Jan 27 22:06:09 2006
@@ -101,7 +101,7 @@
 #  define unix
 #endif
 
-#if defined(linux) || defined(__CYGWIN__) || defined(__MINGW32__)
+#if defined(linux) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__FreeBSD__)
 #  if defined(PPC)
 #    define POWERPC
 #  else
@@ -143,7 +143,7 @@
 #        define alphavmsI
 #      endif
 #    else           /* "vms" not defined if "-W ansi89" used. */
-#      if !defined(linux)
+#      if !defined(linux) && !defined(__FreeBSD__)
 #        define posixSHELL
 #        define posixSHELLalpha
 #        if __D_FLOAT
@@ -456,7 +456,8 @@
 #      endif
 #    endif
 #    if defined(macosX) || defined(__osf__) || defined(__CYGWIN__) || \
-        defined(vms) || defined(sgi) || defined(__MINGW32__)
+        defined(vms) || defined(sgi) || defined(__MINGW32__) || \
+        defined(__FreeBSD__)
 #      define FOPEN64 fopen
 #    else
 #      define FOPEN64 fopen64
