--- src/l64seek.h.orig	2000-12-13 22:56:07 UTC
+++ src/l64seek.h
@@ -33,7 +33,7 @@
 #endif
 
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	typedef off_t off64_t;
 #endif
 
