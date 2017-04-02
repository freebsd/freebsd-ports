--- setup.py.orig	2017-03-31 04:04:10 UTC
+++ setup.py
@@ -22,7 +22,7 @@ setuptools.setup(
         'rtv': ['templates/*'],
         'rtv.packages.praw': ['praw.ini'],
         },
-    data_files=[("share/man/man1", ["rtv.1"])],
+    data_files=[("man/man1", ["rtv.1"])],
     install_requires=[
         'beautifulsoup4',
         'decorator',
