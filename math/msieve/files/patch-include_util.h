--- include/util.h.orig	2008-09-24 15:59:32.000000000 +0200
+++ include/util.h	2009-01-11 23:46:55.000000000 +0100
@@ -202,8 +202,18 @@
    the only CPU that doesn't have these instructions is
    the classic Pentium */
 
+#if defined(CPU_GENERIC)	|| \
+    defined(CPU_PENTIUM2)	|| \
+    defined(CPU_ATHLON)		|| \
+    defined(CPU_PENTIUM3)	|| \
+    defined(CPU_ATHLON_XP)	|| \
+    defined(CPU_PENTIUM4)	|| \
+    defined(CPU_PENTIUM_M)	|| \
+    defined(CPU_CORE)		|| \
+    defined(CPU_OPTERON)
 #define HAS_CMOV
 #define HAS_MMX
+#endif
 
 #if defined(CPU_GENERIC)
 	#define MANUAL_PREFETCH
