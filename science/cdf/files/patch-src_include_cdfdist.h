--- src/include/cdfdist.h.orig	Mon Jan 30 20:05:49 2006
+++ src/include/cdfdist.h	Tue Jan 31 22:26:02 2006
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
@@ -513,7 +514,7 @@
 *****************************************************************************/
 
 #if defined(sun) || defined(MIPSEB) || defined(IBMRS) || defined(HP) || \
-    defined(NeXT) || defined(mac) || defined(POWERPC)
+    defined(NeXT) || defined(mac) || defined(POWERPC) || defined(__sparc64__)
 #  define FP1cpu
 #endif
 
