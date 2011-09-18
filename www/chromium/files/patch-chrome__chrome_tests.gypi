--- chrome/chrome_tests.gypi.orig	2011-07-28 11:02:03.000000000 +0300
+++ chrome/chrome_tests.gypi	2011-09-06 22:02:18.000000000 +0300
@@ -4266,7 +4266,7 @@
                 '../courgette/courgette.gyp:courgette_unittests',
                 'browser_tests',
                 ]}],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 # Reason for disabling UI tests on non-Linux above.
                 'ui_tests',
