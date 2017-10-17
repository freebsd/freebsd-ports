--- net/instaweb/closure.gypi.orig	2017-10-07 00:18:23 UTC
+++ net/instaweb/closure.gypi
@@ -74,7 +74,7 @@
             ],
           }],
           ['js_includes != ""', {
-            'closure_flags': ['<!@(python -c "print \' \'.join([\'--js \' + js for js in \'<(js_includes)\'.split()]) ")'],
+            'closure_flags': ['<!@(python2.7 -c "print \' \'.join([\'--js \' + js for js in \'<(js_includes)\'.split()]) ")'],
           }],
           ['"<!(echo $BUILD_JS)" != "1"', {
             'action': [
