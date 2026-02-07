--- corec/corec/portab.h.orig	2012-12-16 10:29:34 UTC
+++ corec/corec/portab.h
@@ -159,6 +159,9 @@
 
 #elif defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
 
+#if defined(__FreeBSD__)
+#define TARGET_FREEBSD
+#endif
 #define TARGET_LINUX
 
 #ifndef TARGET_QTOPIA // qtopia defines desktop manually
