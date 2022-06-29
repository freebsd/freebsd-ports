--- tools/v8_gypfiles/v8.gyp.orig	2022-05-17 11:37:47 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -977,7 +977,7 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
-        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm", "riscv64", "loong64"]', {
+        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "riscv64", "loong64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
           },
