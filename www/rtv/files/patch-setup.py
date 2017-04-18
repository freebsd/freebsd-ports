--- setup.py.orig	2017-04-10 03:35:24 UTC
+++ setup.py
@@ -62,7 +62,7 @@ setuptools.setup(
         'rtv': ['templates/*'],
         'rtv.packages.praw': ['praw.ini']
     },
-    data_files=[("share/man/man1", ["rtv.1"])],
+    data_files=[("man/man1", ["rtv.1"])],
     install_requires=install_requires,
     tests_require=tests_require,
     extras_require=extras_require,
