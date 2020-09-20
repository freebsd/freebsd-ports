--- source/common/version.cpp.orig	2020-05-29 17:39:35 UTC
+++ source/common/version.cpp
@@ -63,6 +63,8 @@
 #define ONOS    "[Linux]"
 #elif __OpenBSD__
 #define ONOS    "[OpenBSD]"
+#elif __FreeBSD__
+#define ONOS	"[FreeBSD]"
 #elif  __CYGWIN__
 #define ONOS    "[Cygwin]"
 #elif __APPLE__
@@ -71,7 +73,7 @@
 #define ONOS    "[Unk-OS]"
 #endif
 
-#if X86_64
+#if defined(X86_64) || X265_ARCH_ARM64
 #define BITS    "[64 bit]"
 #else
 #define BITS    "[32 bit]"
