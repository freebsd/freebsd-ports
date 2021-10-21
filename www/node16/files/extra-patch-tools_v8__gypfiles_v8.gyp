--- tools/v8_gypfiles/v8.gyp.orig	2021-04-20 11:30:16 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -774,7 +774,7 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
-        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm", "riscv64"]', {
+        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "riscv64"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
           },
