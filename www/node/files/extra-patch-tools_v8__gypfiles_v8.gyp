--- tools/v8_gypfiles/v8.gyp.orig	2020-04-25 08:50:20 UTC
+++ tools/v8_gypfiles/v8.gyp
@@ -805,7 +805,7 @@
         }],
         # Platforms that don't have Compare-And-Swap (CAS) support need to link atomic library
         # to implement atomic memory access
-        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc", "arm"]', {
+        ['v8_current_cpu in ["mips", "mipsel", "mips64", "mips64el", "ppc"]', {
           'link_settings': {
             'libraries': ['-latomic', ],
           },
