--- chrome/chrome_resources.gyp.orig	2016-08-04 11:15:29.707642000 -0400
+++ chrome/chrome_resources.gyp	2016-08-04 11:17:02.866434000 -0400
@@ -321,6 +321,8 @@
                 'platform': 'chromeos'
               }, 'OS=="linux"', {
                 'platform': 'linux'
+              }, 'OS=="freebsd"', {
+                'platform': 'freebsd'
               }, 'OS=="mac"', {
                 'platform': 'mac'
               }, 'OS=="win"', {
