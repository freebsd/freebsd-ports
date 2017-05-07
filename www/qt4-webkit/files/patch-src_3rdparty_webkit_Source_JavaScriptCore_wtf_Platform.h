This patch reportedly fixes build for ARM. See PR 208569

--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h.orig	2017-02-07 10:30:44 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Platform.h
@@ -218,6 +218,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
