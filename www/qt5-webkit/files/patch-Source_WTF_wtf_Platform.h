This patch reportedly fixes build for ARM. See PR 208569

--- Source/WTF/wtf/Platform.h.orig	2016-04-10 06:48:36 UTC
+++ Source/WTF/wtf/Platform.h
@@ -218,6 +218,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
