--- build/make/configure.sh.orig	2015-04-03 18:49:19 UTC
+++ build/make/configure.sh
@@ -831,7 +832,6 @@ process_common_toolchain() {
 
       case ${tgt_cc} in
         gcc)
-          CROSS=${CROSS:-arm-none-linux-gnueabi-}
           link_with_cc=gcc
           setup_gnu_toolchain
           arch_int=${tgt_isa##armv}
