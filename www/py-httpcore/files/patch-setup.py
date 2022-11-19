Obtained from:	https://github.com/encode/httpcore/commit/4cf288e0007cb73561b9020af9228f076ba2a94e

--- setup.py.orig	2022-05-17 12:45:06 UTC
+++ setup.py
@@ -54,7 +54,7 @@ setup(
     include_package_data=True,
     zip_safe=False,
     install_requires=[
-        "h11>=0.11,<0.13",
+        "h11>=0.13,<0.15",
         "sniffio==1.*",
         "anyio==3.*",
         "certifi",
