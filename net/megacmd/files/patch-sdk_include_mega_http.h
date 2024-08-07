--- sdk/include/mega/http.h.orig	2024-05-17 14:19:43 UTC
+++ sdk/include/mega/http.h
@@ -42,7 +42,7 @@
 #pragma warning(pop)
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <netinet/in.h>
 #endif
 
