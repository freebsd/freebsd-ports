--- repo/package/scripts/common/utils.sh.orig	2025-11-09 18:33:45 UTC
+++ repo/package/scripts/common/utils.sh
@@ -22,6 +22,10 @@ else
     DENOURL=https://github.com/denoland/deno/releases/download
     DENOFILES=deno-x86_64-unknown-linux-gnu.zip
     DENO_ARCH_DIR=x86_64
+  elif [[ $NIXARCH == "amd64" ]]; then
+    DENOURL=https://github.com/denoland/deno/releases/download
+    DENOFILES=deno-x86_64-unknown-linux-gnu.zip
+    DENO_ARCH_DIR=x86_64
   elif [[ $NIXARCH == "aarch64" ]]; then
     DENOURL=https://github.com/denoland/deno/releases/download
     DENOFILES=deno-aarch64-unknown-linux-gnu.zip
