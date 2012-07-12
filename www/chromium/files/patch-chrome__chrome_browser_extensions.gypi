--- chrome/chrome_browser_extensions.gypi.orig	2012-06-06 00:40:02.000000000 +0300
+++ chrome/chrome_browser_extensions.gypi	2012-06-06 00:51:18.000000000 +0300
@@ -650,7 +650,7 @@
             }],
           ],
         }],
-        ['OS=="android"', {
+        ['OS=="android" or OS=="freebsd"', {
           'sources!': [
             'browser/extensions/api/usb/usb_api.cc',
             'browser/extensions/api/usb/usb_api.h',
