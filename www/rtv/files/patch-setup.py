--- setup.py.orig	2016-10-18 02:27:09 UTC
+++ setup.py
@@ -18,7 +18,7 @@ setuptools.setup(
     keywords='reddit terminal praw curses',
     packages=['rtv'],
     package_data={'rtv': ['templates/*']},
-    data_files=[("share/man/man1", ["rtv.1"])],
+    data_files=[("man/man1", ["rtv.1"])],
     install_requires=requirements,
     entry_points={'console_scripts': ['rtv=rtv.__main__:main']},
     classifiers=[
