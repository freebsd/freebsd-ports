--- node.gyp.orig	2017-03-24 18:42:07.195465000 +0100
+++ node.gyp	2017-03-24 18:42:26.672322000 +0100
@@ -842,6 +842,12 @@
                 '<(OBJ_DIR)/node/src/node_dtrace_ustack.o'
               ],
               'conditions': [
+                [ 'target_arch=="arm"', {
+                  'action': [
+                    'dtrace', '-32', '-I<(SHARED_INTERMEDIATE_DIR)', '-Isrc',
+                    '-C', '-G', '-s', 'src/v8ustack.d', '-o', '<@(_outputs)',
+                  ]
+                } ],
                 [ 'target_arch=="ia32"', {
                   'action': [
                     'dtrace', '-32', '-I<(SHARED_INTERMEDIATE_DIR)', '-Isrc',
