--- src/3rdparty/chromium/third_party/libvpx/generate_gni.sh.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/libvpx/generate_gni.sh
@@ -429,7 +429,7 @@ gen_config_files linux/loongarch \
 gen_config_files linux/mips64el "--target=mips64-linux-gcc ${all_platforms}"
 gen_config_files linux/loongarch \
   "--target=loongarch64-linux-gcc ${all_platforms}"
-gen_config_files linux/ppc64 "--target=ppc64le-linux-gcc ${all_platforms}"
+gen_config_files linux/ppc64 "--target=generic-gnu ${all_platforms}"
 gen_config_files linux/generic "--target=generic-gnu $HIGHBD ${all_platforms}"
 gen_config_files win/arm64-highbd \
   "--target=arm64-win64-vs15 ${all_platforms} ${HIGHBD} ${disable_sve}"
@@ -493,7 +493,7 @@ gen_rtcd_header linux/loongarch loongarch
 gen_rtcd_header linux/mipsel mipsel
 gen_rtcd_header linux/mips64el mips64el
 gen_rtcd_header linux/loongarch loongarch
-gen_rtcd_header linux/ppc64 ppc
+gen_rtcd_header linux/ppc64 generic
 gen_rtcd_header linux/generic generic
 gen_rtcd_header win/arm64-highbd armv8 "${require_neon} ${disable_sve}"
 gen_rtcd_header win/ia32 x86 "${require_sse3}"
