--- src/core/global/qglobal.h.orig	2022-06-04 14:31:11 UTC
+++ src/core/global/qglobal.h
@@ -101,13 +101,13 @@
 
 #   define Q_PROCESSOR_ARM_32
 
-#   if defined(__ARM_ARCH_7__)
+#   if defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__)
 #      define Q_PROCESSOR_ARM      7
 #      define Q_PROCESSOR_ARM_V7
 
-#   elif defined(__ARM_ARCH_6__)
+#   elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6KZ__)
 #      define Q_PROCESSOR_ARM      6
-#      define Q_PROCESSOR_ARM_V8
+#      define Q_PROCESSOR_ARM_V6
 
 #   elif defined(__ARM_ARCH_5__)
 #      define Q_PROCESSOR_ARM      5
