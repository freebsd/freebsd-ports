--- build/pagespeed_overrides.gypi.orig	2017-10-06 11:59:51 UTC
+++ build/pagespeed_overrides.gypi
@@ -90,14 +90,13 @@
         ],
       },
     }],
     ['os_posix==1 and OS!="mac"', {
       'target_defaults': {
         'ldflags': [
-          # Fail to link if there are any undefined symbols.
-          '-Wl,-z,defs',
+          '-Wl,-z,lazy',
         ],
       }
     }],
     ['OS=="mac"', {
       'target_defaults': {
         'xcode_settings': {
