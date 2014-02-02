--- ./setup.py.orig	2013-12-21 08:59:30.000000000 +1100
+++ ./setup.py	2014-01-29 19:27:01.992938843 +1100
@@ -24,7 +24,7 @@
                                       'screenshots', 'screenshots.*']),
     package_data={
         '':       ['*.txt',  '*.md', '*.rst', '*.json', '*.conf', '*.html',
-                   '*.css', '*.ico', '*.png', '../LICENSE'],
+                   '*.css', '*.ico', '*.png'],
         'halite': ['app/*.txt', 'app/*/*.txt',
                    'app/*.ico', 'app/*/*.ico',
                    'app/*.png', 'app/*/*.png', 
