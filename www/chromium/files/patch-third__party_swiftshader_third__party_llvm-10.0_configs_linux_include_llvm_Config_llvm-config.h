--- third_party/swiftshader/third_party/llvm-10.0/configs/linux/include/llvm/Config/llvm-config.h.orig	2020-08-18 18:42:46 UTC
+++ third_party/swiftshader/third_party/llvm-10.0/configs/linux/include/llvm/Config/llvm-config.h
@@ -35,7 +35,7 @@
 #elif defined(__arm__)
 #define LLVM_DEFAULT_TARGET_TRIPLE "armv7-linux-gnueabihf"
 #elif defined(__aarch64__)
-#define LLVM_DEFAULT_TARGET_TRIPLE "aarch64-linux-gnu"
+#define LLVM_DEFAULT_TARGET_TRIPLE "aarch64-portbld-freebsd"
 #elif defined(__mips__)
 #define LLVM_DEFAULT_TARGET_TRIPLE "mipsel-linux-gnu"
 #elif defined(__mips64)
@@ -60,7 +60,7 @@
 #elif defined(__arm__)
 #define LLVM_HOST_TRIPLE "armv7-linux-gnueabihf"
 #elif defined(__aarch64__)
-#define LLVM_HOST_TRIPLE "aarch64-linux-gnu"
+#define LLVM_HOST_TRIPLE "aarch64-portbld-freebsd"
 #elif defined(__mips__)
 #define LLVM_HOST_TRIPLE "mipsel-linux-gnu"
 #elif defined(__mips64)
