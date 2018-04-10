- Add armv6 targets where NEON depends on CFLAGS
- Recognize DragonFly as x86_64-linux-gcc target by default

--- build/make/configure.sh.orig	2018-01-24 22:25:44 UTC
+++ build/make/configure.sh
@@ -696,6 +696,14 @@ process_common_toolchain() {
       aarch64*)
         tgt_isa=arm64
         ;;
+      armv6*-gnueabihf)
+        tgt_isa=armv6
+        float_abi=hard
+        ;;
+      armv6*-gnueabi)
+        tgt_isa=armv6
+        float_abi=softfp
+        ;;
       armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf)
         tgt_isa=armv7
         float_abi=hard
@@ -767,7 +767,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*dragonfly*|*bsd*)
         tgt_os=linux
         ;;
       *solaris2.10)
