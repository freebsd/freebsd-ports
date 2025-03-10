--- setup.py.orig	2025-01-27 13:14:54 UTC
+++ setup.py
@@ -47,7 +47,7 @@ setup(
         "setuptools_scm[toml]>=6.2",
     ],
     install_requires=[
-        "protobuf>=3.19.4, <4",
+        "protobuf>=3.19.4",
         "fonttools",
         "importlib_resources ; python_version < '3.10'",
     ],
