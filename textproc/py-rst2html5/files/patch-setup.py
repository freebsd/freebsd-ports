# Conflicts with docutils >-= 0.13.1
# 1d6174076454 doesn't actually resolve the (file) conflict
# https://bitbucket.org/andre_felipe_dias/rst2html5/issues/27/
# https://github.com/getnikola/nikola/issues/2657
# https://github.com/marianoguerra/rst2html5/issues/87

--- setup.py.orig	2018-05-22 02:47:00 UTC
+++ setup.py
@@ -51,8 +51,8 @@ setup(
     include_package_data=True,
     entry_points={
         'console_scripts': [
-            'rst2html5 = rst2html5_:main',
-            'rst2html5.py = rst2html5_:main',  # overrides docutils' rst2html5.py
+            'rst2html5-rst2html5 = rst2html5_:main',
+            'rst2html5-rst2html5.py = rst2html5_:main',  # overrides docutils' rst2html5.py
         ],
     },
 )
