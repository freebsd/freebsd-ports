--- src/3rdparty/chromium/third_party/dawn/src/dawn/common/Platform.h.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/dawn/src/dawn/common/Platform.h
@@ -60,6 +60,11 @@
 #error "Unsupported Windows platform."
 #endif
 
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
+#define DAWN_PLATFORM_IS_LINUX 1
+#define DAWN_PLATFORM_IS_BSD 1
+#define DAWN_PLATFORM_IS_POSIX 1
+
 #elif defined(__linux__)
 #define DAWN_PLATFORM_IS_LINUX 1
 #define DAWN_PLATFORM_IS_POSIX 1
@@ -163,10 +168,10 @@
 #elif defined(__s390x__)
 #define DAWN_PLATFORM_IS_S390X 1
 
-#elif defined(__PPC__)
-#define DAWN_PLATFORM_IS_PPC 1
 #elif defined(__PPC64__)
 #define DAWN_PLATFORM_IS_PPC64 1
+#elif defined(__PPC__)
+#define DAWN_PLATFORM_IS_PPC 1
 
 #elif defined(__wasm32__)
 #define DAWN_PLATFORM_IS_WASM32 1
@@ -189,7 +194,7 @@ static_assert(sizeof(sizeof(char)) == 8, "Expect sizeo
 static_assert(sizeof(sizeof(char)) == 8, "Expect sizeof(size_t) == 8");
 #elif defined(DAWN_PLATFORM_IS_I386) || defined(DAWN_PLATFORM_IS_ARM32) ||   \
     defined(DAWN_PLATFORM_IS_RISCV32) || defined(DAWN_PLATFORM_IS_MIPS32) || \
-    defined(DAWN_PLATFORM_IS_S390) || defined(DAWN_PLATFORM_IS_PPC32) ||     \
+    defined(DAWN_PLATFORM_IS_S390) || defined(DAWN_PLATFORM_IS_PPC) ||       \
     defined(DAWN_PLATFORM_IS_LOONGARCH32) || defined(DAWN_PLATFORM_IS_WASM32)
 #define DAWN_PLATFORM_IS_32_BIT 1
 static_assert(sizeof(sizeof(char)) == 4, "Expect sizeof(size_t) == 4");
