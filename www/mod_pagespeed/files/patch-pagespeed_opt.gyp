--- pagespeed/opt.gyp.orig	2017-09-12 22:04:16 UTC
+++ pagespeed/opt.gyp
@@ -20,8 +20,13 @@
     # errors.
     'chromium_code': 1,
     'protoc_out_dir': '<(SHARED_INTERMEDIATE_DIR)/protoc_out/instaweb',
-    'protoc_executable':
-        '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+    'conditions': [
+      ['use_system_protobuf==0', {
+        'protoc_executable': '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+      }, { # use_system_protobuf==1
+        'protoc_executable': '<!(which protoc)',
+      }],
+    ],
     'compiled_js_dir': '<(SHARED_INTERMEDIATE_DIR)/closure_out/instaweb',
     'data2c_out_dir': '<(SHARED_INTERMEDIATE_DIR)/data2c_out/instaweb',
     'data2c_exe':
