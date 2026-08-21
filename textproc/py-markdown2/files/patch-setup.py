--- setup.py.orig	2026-08-21 11:55:50 UTC
+++ setup.py
@@ -49,7 +49,6 @@ setup(
     platforms=["any"],
     py_modules=["markdown2"],
     package_dir={"": "lib"},
-    data_files=[("testing", ["tox.ini"])],
     entry_points={
         "console_scripts": [
             "markdown2 = markdown2:main"
