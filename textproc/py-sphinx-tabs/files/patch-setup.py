--- setup.py.orig	2021-05-11 20:38:43 UTC
+++ setup.py
@@ -25,7 +25,7 @@ setup(
     url="https://github.com/executablebooks/sphinx-tabs",
     license="MIT",
     python_requires="~=3.6",
-    install_requires=["sphinx>=2,<5", "pygments", "docutils~=0.16.0"],
+    install_requires=["sphinx>=2,<5", "pygments", "docutils~=0.16"],
     extras_require={
         "testing": [
             "coverage",
