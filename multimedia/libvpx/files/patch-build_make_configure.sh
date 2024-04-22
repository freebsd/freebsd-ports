- Add armv6 targets and try NEON there
- Recognize DragonFly as x86_64-linux-gcc target by default
- Don't override -march= on armv6, armv7 and aarch64

--- build/make/configure.sh.orig	2024-01-09 21:12:22 UTC
+++ build/make/configure.sh
@@ -752,6 +752,14 @@ process_common_toolchain() {
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
@@ -806,7 +814,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*dragonfly*|*bsd*)
         tgt_os=linux
         ;;
       *solaris2.10)
@@ -997,7 +1005,7 @@ EOF
             fi
           done
           ;;
-        armv7|armv7s)
+        armv6|armv7|armv7s)
           soft_enable neon
           # Only enable neon_asm when neon is also enabled.
           enabled neon && soft_enable neon_asm
@@ -1017,29 +1025,6 @@ EOF
           arch_int=${tgt_isa##armv}
           arch_int=${arch_int%%te}
           tune_cflags="-mtune="
-          if [ ${tgt_isa} = "armv7" ] || [ ${tgt_isa} = "armv7s" ]; then
-            if [ -z "${float_abi}" ]; then
-              check_cpp <<EOF && float_abi=hard || float_abi=softfp
-#ifndef __ARM_PCS_VFP
-#error "not hardfp"
-#endif
-EOF
-            fi
-            check_add_cflags  -march=armv7-a -mfloat-abi=${float_abi}
-            check_add_asflags -march=armv7-a -mfloat-abi=${float_abi}
-
-            if enabled neon || enabled neon_asm; then
-              check_add_cflags -mfpu=neon #-ftree-vectorize
-              check_add_asflags -mfpu=neon
-            fi
-          elif [ ${tgt_isa} = "arm64" ] || [ ${tgt_isa} = "armv8" ]; then
-            check_add_cflags -march=armv8-a
-            check_add_asflags -march=armv8-a
-          else
-            check_add_cflags -march=${tgt_isa}
-            check_add_asflags -march=${tgt_isa}
-          fi
-
           enabled debug && add_asflags -g
           asm_conversion_cmd="${source_path_mk}/build/make/ads2gas.pl"
 
