--- setup.py.orig	2025-11-14 15:00:34 UTC
+++ setup.py
@@ -303,7 +303,7 @@ setup(
 setup(
     setup_requires=[
         "cython>=3.0,<4.0",
-        "numpy>=2.0.0,<3.0.0",
+        "numpy>=1.19.3,<3.0.0",
     ],
     install_requires=[
         "numpy>=1.15.0,<3.0.0; python_version < '3.9'",
