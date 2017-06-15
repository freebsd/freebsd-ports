--- setup.py.orig	2017-01-13 02:49:35 UTC
+++ setup.py
@@ -16,7 +16,7 @@ setuptools.setup(
     keywords='reddit terminal praw curses',
     packages=['rtv'],
     package_data={'rtv': ['templates/*']},
-    data_files=[("share/man/man1", ["rtv.1"])],
+    data_files=[("man/man1", ["rtv.1"])],
     install_requires=[
         'praw >=3.5, <4',
         'six',
