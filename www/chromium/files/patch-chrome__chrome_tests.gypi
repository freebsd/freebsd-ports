--- chrome/chrome_tests.gypi.orig	2011-06-24 11:31:19.000000000 +0300
+++ chrome/chrome_tests.gypi	2011-06-26 20:25:42.958784006 +0300
@@ -2963,7 +2963,7 @@
             '../third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp:webcore',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
             '../tools/xdisplaycheck/xdisplaycheck.gyp:xdisplaycheck',
@@ -3964,7 +3964,7 @@
                 '../courgette/courgette.gyp:courgette_unittests',
                 'browser_tests',
                 ]}],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'dependencies': [
                 # Reason for disabling UI tests on non-Linux above.
                 'ui_tests',
