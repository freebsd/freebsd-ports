--- setup.py.orig	2025-01-12 18:52:51 UTC
+++ setup.py
@@ -303,7 +303,7 @@ setup(
 setup(
     setup_requires=[
         "cython>=0.25,<4.0",
-        "numpy>=2.0.0,<3.0.0",
+        "numpy>=1.19.0,<3.0.0",
     ],
     install_requires=[
         "numpy>=1.15.0,<3.0.0; python_version < '3.9'",
