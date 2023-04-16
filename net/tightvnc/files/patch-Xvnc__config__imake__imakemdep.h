--- Xvnc/config/imake/imakemdep.h.orig	2003-02-19 16:39:54 UTC
+++ Xvnc/config/imake/imakemdep.h
@@ -225,6 +225,9 @@ in this Software without prior written authorization f
 #ifdef hpux
 #define USE_CC_E
 #endif
+#if defined(__FreeBSD__)
+#define USE_CC_E
+#endif
 #ifdef WIN32
 #define USE_CC_E
 #define DEFAULT_CC "cl"
@@ -253,7 +256,7 @@ in this Software without prior written authorization f
 #ifdef _CRAY
 #define DEFAULT_CPP "/lib/pcpp"
 #endif
-#if defined(__386BSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__386BSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #define DEFAULT_CPP "/usr/libexec/cpp"
 #endif
 #if defined(__sgi) && defined(__ANSI_CPP__)
