--- ui/accessibility/accessibility.gyp.orig	2016-05-11 19:02:35 UTC
+++ ui/accessibility/accessibility.gyp
@@ -64,7 +64,7 @@
             '../../third_party/iaccessible2/iaccessible2.gyp:iaccessible2'
           ],
         }],
-        ['OS=="linux" and chromeos==0 and use_x11==1', {
+        ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_x11==1', {
           'dependencies': [
             '../../build/linux/system.gyp:atk',
             '../../build/linux/system.gyp:gconf',
@@ -81,7 +81,7 @@
             ],
           },
         }],
-        ['OS!="linux" or chromeos==1 or use_x11==0', {
+        ['(OS!="linux" and os_bsd==0) or chromeos==1 or use_x11==0', {
           'sources!': [
             'platform/ax_platform_node_auralinux.cc',
             'platform/ax_platform_node_auralinux.h',
