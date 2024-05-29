- Add armv6 targets and try NEON there
- Recognize DragonFly as x86_64-linux-gcc target by default
- Don't override -march= on armv6, armv7 and aarch64

--- build/make/configure.sh.orig	2024-05-29 20:00:23 UTC
+++ build/make/configure.sh
@@ -785,6 +785,14 @@ process_common_toolchain() {
     case "$gcctarget" in
       aarch64*)
         tgt_isa=arm64
+        ;;
+      armv6*-gnueabihf)
+        tgt_isa=armv6
+        float_abi=hard
+        ;;
+      armv6*-gnueabi)
+        tgt_isa=armv6
+        float_abi=softfp
         ;;
       armv7*-hardfloat* | armv7*-gnueabihf | arm-*-gnueabihf)
         tgt_isa=armv7
@@ -840,7 +848,7 @@ process_common_toolchain() {
         [ -z "$tgt_isa" ] && tgt_isa=x86
         tgt_os=win32
         ;;
-      *linux*|*bsd*)
+      *linux*|*dragonfly*|*bsd*)
         tgt_os=linux
         ;;
       *solaris2.10)
@@ -1015,7 +1023,7 @@ EOF
     arm*)
       soft_enable runtime_cpu_detect
 
-      if [ ${tgt_isa} = "armv7" ] || [ ${tgt_isa} = "armv7s" ]; then
+      if [ ${tgt_isa} = "armv6" ] || [ ${tgt_isa} = "armv7" ] || [ ${tgt_isa} = "armv7s" ]; then
         soft_enable neon
         # Only enable neon_asm when neon is also enabled.
         enabled neon && soft_enable neon_asm
@@ -1033,29 +1041,6 @@ EOF
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
 
