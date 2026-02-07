Index: src/3rdparty/PhysX/pxshared/include/foundation/PxPreprocessor.h
--- src/3rdparty/PhysX/pxshared/include/foundation/PxPreprocessor.h.orig	2023-09-24 11:12:43 UTC
+++ src/3rdparty/PhysX/pxshared/include/foundation/PxPreprocessor.h
@@ -100,6 +100,9 @@ Operating system defines, see http://sourceforge.net/p
 #define PX_ANDROID 1
 #elif defined(__linux__) || defined (__EMSCRIPTEN__) // note: __ANDROID__ implies __linux__
 #define PX_LINUX 1
+#elif defined(__FreeBSD__)
+#define PX_LINUX 1
+#define PX_FREEBSD 1
 #elif defined(TARGET_OS_IOS) && TARGET_OS_IOS && defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
 #define PX_IOS 1
 #elif defined(__APPLE__)
@@ -188,6 +191,9 @@ define anything not defined on this platform to 0
 #ifndef PX_LINUX
 #define PX_LINUX 0
 #endif
+#ifndef PX_FREEBSD
+#define PX_FREEBSD 0
+#endif
 #ifndef PX_IOS
 #define PX_IOS 0
 #endif
@@ -278,7 +284,7 @@ family shortcuts
 // architecture
 #define PX_INTEL_FAMILY (PX_X64 || PX_X86)
 #define PX_ARM_FAMILY (PX_ARM || PX_A64)
-#define PX_P64_FAMILY (PX_X64 || PX_A64 || PX_WASM_64) // shortcut for 64-bit architectures
+#define PX_P64_FAMILY (PX_X64 || PX_A64 || PX_WASM_64 || __powerpc64__) // shortcut for 64-bit architectures
 
 /**
 C++ standard library defines
