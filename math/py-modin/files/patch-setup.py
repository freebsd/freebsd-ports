--- setup.py.orig	2024-09-11 12:58:49 UTC
+++ setup.py
@@ -52,7 +52,7 @@ setup(
     long_description=long_description,
     long_description_content_type="text/markdown",
     install_requires=[
-        "pandas>=2.2,<2.3",
+        "pandas>=2,<2.3",
         "packaging>=21.0",
         "numpy>=1.22.4",
         "fsspec>=2022.11.0",
