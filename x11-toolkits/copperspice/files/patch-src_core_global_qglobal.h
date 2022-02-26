--- src/core/global/qglobal.h.orig	2022-02-26 11:39:19 UTC
+++ src/core/global/qglobal.h
@@ -118,6 +118,16 @@
 
 #   endif
 
+#elif defined(__powerpc64__)
+// 64-bit POWER
+
+#  define Q_PROCESSOR_PPC_64
+
+#elif defined(__powerpc__)
+// 32-bit POWER
+
+#  define Q_PROCESSOR_PPC
+
 #else
 #   error Unable to detect system architecture, contact CopperSpice development
 
