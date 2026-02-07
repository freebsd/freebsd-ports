--- binding.gyp.orig	2025-04-10 22:01:02 UTC
+++ binding.gyp
@@ -5,10 +5,10 @@
       'target_name': 'node_sqlcipher',
       'dependencies': [
         'deps/sqlcipher/sqlcipher.gyp:sqlcipher',
-        'deps/extension/extension.gyp:extension',
         "<!(node -p \"require('node-addon-api').targets\"):node_addon_api",
       ],
       'sources': ['src/addon.cc'],
+      'include_dirs': ['PREFIX/include'],
       'conditions': [
         ['OS=="linux"', {
           'ldflags': [
