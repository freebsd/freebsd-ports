--- setup.py.orig	2018-10-27 04:42:31 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(
                                       'screenshots', 'screenshots.*']),
     package_data={
         '':       ['*.txt',  '*.md', '*.rst', '*.json', '*.conf', '*.html',
-                   '*.css', '*.ico', '*.png', '../LICENSE'],
+                   '*.css', '*.ico', '*.png'],
         'halite': pkg_files},
     install_requires = [''],
     extras_require = {}, )
