--- core/DesktopEditor/xml/libxml2/trionan.c.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/xml/libxml2/trionan.c
@@ -51,7 +51,7 @@
 # include <signal.h>
 #endif
 #if defined(TRIO_COMPILER_DECC)
-#  if defined(__linux__)
+#  if defined(__linux__) || defined(__FreeBSD__)
 #   include <cpml.h>
 #  else
 #   include <fp_class.h>
@@ -85,7 +85,7 @@
 #    error "Must be compiled with option -ieee"
 #   endif
 #  endif
-# elif defined(TRIO_COMPILER_GCC) && (defined(__osf__) || defined(__linux__))
+# elif defined(TRIO_COMPILER_GCC) && (defined(__osf__) || defined(__linux__)) || defined(__FreeBSD__)
 #  error "Must be compiled with option -mieee"
 # endif
 #endif /* __alpha && ! _IEEE_FP */
@@ -443,7 +443,7 @@ trio_isinf
 TRIO_ARGS1((number),
 	   double number)
 {
-#if defined(TRIO_COMPILER_DECC) && !defined(__linux__)
+#if defined(TRIO_COMPILER_DECC) && !defined(__linux__) && !defined(__FreeBSD__)
   /*
    * DECC has an isinf() macro, but it works differently than that
    * of C99, so we use the fp_class() function instead.
