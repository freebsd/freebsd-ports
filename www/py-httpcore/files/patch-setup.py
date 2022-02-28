--- setup.py.orig	2022-01-18 11:44:56 UTC
+++ setup.py
@@ -54,7 +54,7 @@ setup(
     include_package_data=True,
     zip_safe=False,
     install_requires=[
-        "h11>=0.11,<0.13",
+        "h11>=0.11,<0.14",
         "sniffio==1.*",
         "anyio==3.*",
         "certifi",
