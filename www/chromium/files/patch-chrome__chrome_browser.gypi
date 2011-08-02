--- chrome/chrome_browser.gypi.orig	2011-06-24 11:31:19.000000000 +0300
+++ chrome/chrome_browser.gypi	2011-06-26 20:14:19.677781532 +0300
@@ -3679,12 +3679,6 @@
             '../build/linux/system.gyp:x11',
             '../third_party/undoview/undoview.gyp:undoview',
           ],
-          'link_settings': {
-            'libraries': [
-              # For dlsym() in 'browser/zygote_main_linux.cc'
-              '-ldl',
-            ],
-          },
           'sources!': [
             'browser/ui/views/extensions/extension_view.cc',
             'browser/ui/views/extensions/extension_view.h',
