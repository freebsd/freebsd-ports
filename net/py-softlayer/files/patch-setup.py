--- setup.py.orig	2022-03-30 21:27:21 UTC
+++ setup.py
@@ -35,7 +35,7 @@ setup(
     python_requires='>=3.5',
     install_requires=[
         'prettytable >= 2.0.0',
-        'click == 8.0.4',
+        'click >= 8.0.3, < 8.1.0',
         'requests >= 2.20.0',
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
