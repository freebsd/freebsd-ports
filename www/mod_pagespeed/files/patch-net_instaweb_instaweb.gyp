--- net/instaweb/instaweb.gyp.orig	2017-06-08 22:22:39 UTC
+++ net/instaweb/instaweb.gyp
@@ -34,9 +34,14 @@
 {
   'variables': {
     'instaweb_root': '../..',
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
     'compiled_js_dir': '<(SHARED_INTERMEDIATE_DIR)/closure_out/instaweb',
     'data2c_out_dir': '<(SHARED_INTERMEDIATE_DIR)/data2c_out/instaweb',
     'data2c_exe':
