--- setup.py.orig	2022-06-25 23:31:53 UTC
+++ setup.py
@@ -25,7 +25,7 @@ setup(
     url="https://github.com/executablebooks/sphinx-tabs",
     license="MIT",
     python_requires="~=3.7",
-    install_requires=["sphinx>=2,<6", "pygments", "docutils~=0.17.0", "jinja2<3.1.0"],
+    install_requires=["sphinx>=2,<6", "pygments", "docutils~=0.17.0"],
     extras_require={
         "testing": [
             "coverage",
