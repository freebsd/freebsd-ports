--- src/megacmdshell/megacmdshellcommunications.cpp.orig	2024-05-20 12:29:43 UTC
+++ src/megacmdshell/megacmdshellcommunications.cpp
@@ -55,7 +55,7 @@
 #include <limits.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <netinet/in.h>
 #endif
 
