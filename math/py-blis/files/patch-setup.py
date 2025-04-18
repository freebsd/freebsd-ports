--- setup.py.orig	2025-04-03 12:23:45 UTC
+++ setup.py
@@ -302,8 +302,8 @@ setup(
 
 setup(
     setup_requires=[
-        "cython>=3.0,<4.0",
-        "numpy>=2.0.0,<3.0.0",
+        "cython>=0,<4.0",
+        "numpy>=1.19.0,<3.0.0",
     ],
     install_requires=[
         "numpy>=1.15.0,<3.0.0; python_version < '3.9'",
