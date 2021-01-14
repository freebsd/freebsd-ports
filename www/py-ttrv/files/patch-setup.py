--- setup.py.orig	2020-12-08 23:08:30 UTC
+++ setup.py
@@ -63,7 +63,7 @@ setuptools.setup(
         'ttrv': ['templates/*', 'themes/*'],
         'ttrv.packages.praw': ['praw.ini']
     },
-    data_files=[("share/man/man1", ["ttrv.1"])],
+    data_files=[("man/man1", ["ttrv.1"])],
     install_requires=install_requires,
     tests_require=tests_require,
     extras_require=extras_require,
