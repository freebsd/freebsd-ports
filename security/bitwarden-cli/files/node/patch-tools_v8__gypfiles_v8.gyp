--- tools/v8_gypfiles/v8.gyp.orig	2025-05-14 12:21:17 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -1343,7 +1343,7 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
-        ['v8_current_cpu in ["mips64", "mips64el", "ppc", "arm", "riscv64", "loong64"]', {
+        ['v8_current_cpu in ["mips64", "mips64el", "ppc", "riscv64", "loong64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
           },
