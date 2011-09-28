--- ./corec/corec/portab.h.orig	2011-09-25 11:25:46.000000000 +0200
+++ ./corec/corec/portab.h	2011-09-28 16:25:47.730826509 +0200
@@ -159,6 +159,9 @@
 
 #elif defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
+#if defined(__FreeBSD__)
+#define TARGET_FREEBSD
+#endif
 #define TARGET_LINUX
 
 #ifndef TARGET_QTOPIA // qtopia defines desktop manually
