--- arch.h.orig	Thu Sep  5 01:04:40 2002
+++ arch.h	Thu Sep  5 01:05:15 2002
@@ -83,7 +83,7 @@
 #endif
 
 #ifdef __FreeBSD__
-#if __FreeBSD__ == 4
+#if __FreeBSD__ >= 4
 #define ARCH_PC_FREEBSD4
 #else
 #define ARCH_PC_FREEBSD3
