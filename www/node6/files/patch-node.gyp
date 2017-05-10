--- node.gyp.orig	2017-05-10 12:20:05 UTC
+++ node.gyp
@@ -818,6 +818,12 @@
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
