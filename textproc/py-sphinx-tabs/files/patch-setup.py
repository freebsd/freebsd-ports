--- setup.py.orig	2022-07-02 09:46:49 UTC
+++ setup.py
@@ -25,7 +25,7 @@ setup(
     url="https://github.com/executablebooks/sphinx-tabs",
     license="MIT",
     python_requires="~=3.7",
-    install_requires=["sphinx", "pygments", "docutils~=0.18.0"],
+    install_requires=["sphinx", "pygments", "docutils>=0.18.0,<0.22.0"],
     extras_require={
         "testing": [
             "coverage",
