--- dune/pdelab/common/clock.cc.orig	2020-03-15 02:50:50 UTC
+++ dune/pdelab/common/clock.cc
@@ -5,7 +5,7 @@
 #if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE < 199309L
 #undef _POSIX_C_SOURCE
 #endif
-#if !defined(_POSIX_C_SOURCE) && !defined(__APPLE__)
+#if !defined(_POSIX_C_SOURCE) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #define _POSIX_C_SOURCE 199309L
 #endif
 
