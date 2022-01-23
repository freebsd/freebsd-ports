--- setup.py.orig	2022-01-10 10:21:14 UTC
+++ setup.py
@@ -29,7 +29,7 @@ setup(
     packages=find_packages(),
     install_requires=[
         "beautifulsoup4>=4.6.1,<5",
-        "docutils>=0.15,<0.17",
+        "docutils>=0.17.1",
         'importlib-resources>=3.0,<3.5; python_version < "3.7"',
         "pydata-sphinx-theme~=0.7.2",
         "pyyaml",
