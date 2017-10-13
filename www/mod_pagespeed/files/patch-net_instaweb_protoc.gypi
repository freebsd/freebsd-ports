--- net/instaweb/protoc.gypi.orig	2017-06-08 22:22:39 UTC
+++ net/instaweb/protoc.gypi
@@ -18,7 +18,13 @@
     'has_services%': 0,
     # TODO(cheesy): Just remove these variables, since they are basically
     # global, plus we depend directly on protoc anyway.
-    'protoc_executable%': '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+    'conditions': [
+      ['use_system_protobuf==0', {
+        'protoc_executable': '<(PRODUCT_DIR)/<(EXECUTABLE_PREFIX)protoc<(EXECUTABLE_SUFFIX)',
+      }, { # use_system_protobuf==1
+        'protoc_executable': '<!(which protoc)',
+      }],
+    ],
     'protoc_out_dir%': '<(SHARED_INTERMEDIATE_DIR)/protoc_out/instaweb',
   },
   'rules': [
@@ -29,8 +35,8 @@
       'process_outputs_as_sources': 1,
       'variables': {
         'protoc_args': [
-          '--proto_path=<(protoc_out_dir)/',
-          '--cpp_out=<(protoc_out_dir)',
+          '--proto_path=<(protoc_out_dir)/',
+          '--cpp_out=<(protoc_out_dir)',
         ],
       },
       'inputs': [
@@ -39,9 +45,9 @@
       ],
       'message': 'Generating C++ code from <(RULE_INPUT_PATH)',
       'outputs': [
-        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).pb.h',
-        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).pb.cc',
-        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).proto',
+        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).pb.h',
+        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).pb.cc',
+        '<(protoc_out_dir)/<(instaweb_protoc_subdir)/<(RULE_INPUT_ROOT).proto',
       ],
       'conditions': [
         ['has_services != 0', {
