--- common.gypi.orig	2026-09-08 00:00:00 UTC
+++ common.gypi
@@ -75,6 +75,9 @@
     # Disable v8 hugepage by default.
     'v8_enable_hugepage%': 0,
 
+    # Disabled by configure --v8-lite-mode.
+    'v8_enable_webassembly%': 1,
+
     # This is more of a V8 dev setting
     # https://github.com/nodejs/node/pull/22920/files#r222779926
     'v8_enable_fast_mksnapshot': 0,
@@ -509,6 +512,9 @@
       ['v8_enable_v8_checks == 1', {
         'defines': ['V8_ENABLE_CHECKS'],
       }],
+      ['v8_enable_webassembly == 1', {
+        'defines': ['V8_ENABLE_WEBASSEMBLY'],
+      }],
       ['v8_enable_pointer_compression == 1', {
         'defines': ['V8_COMPRESS_POINTERS'],
       }],
