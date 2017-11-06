--- pagespeed/kernel.gyp.orig	2017-09-12 22:02:20 UTC
+++ pagespeed/kernel.gyp
@@ -16,8 +16,13 @@
   'variables': {
     'instaweb_root': '..',
-    'protoc_out_dir': '<(SHARED_INTERMEDIATE_DIR)/protoc_out/instaweb',
-    'protoc_executable':
-        '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+    'protoc_out_dir': '<(SHARED_INTERMEDIATE_DIR)/protoc_out/instaweb',
+    'conditions': [
+      ['use_system_protobuf==0', {
+        'protoc_executable': '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+      }, { # use_system_protobuf==1
+        'protoc_executable': '<!(which protoc)',
+      }],
+    ],
     'data2c_out_dir': '<(SHARED_INTERMEDIATE_DIR)/data2c_out/instaweb',
     'data2c_exe':
         '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)instaweb_data2c<(EXECUTABLE_SUFFIX)',
