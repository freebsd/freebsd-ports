--- setup.py.orig	2020-05-29 10:29:22 UTC
+++ setup.py
@@ -61,7 +61,7 @@ setup(
         "chardet==3.*",
         "idna==2.*",
         "rfc3986>=1.3,<2",
-        "httpcore==0.9.*",
+        "httpcore>=0.9",
     ],
     classifiers=[
         "Development Status :: 4 - Beta",
