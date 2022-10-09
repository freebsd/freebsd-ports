--- setup.py.orig	2022-05-14 09:12:21 UTC
+++ setup.py
@@ -98,9 +98,9 @@ setup(
     # Dependencies
     install_requires=[
         "nassl>=4.0.1,<5.0.0",
-        "cryptography>=2.6,<38.0.0",
+        "cryptography>=2.6,<39.0.0",
         "tls-parser>=2.0.0,<3.0.0",
-        "pydantic>=1.7,<1.10",
+        "pydantic>=1.7,<1.11",
     ],
     # cx_freeze info for Windows builds with Python embedded
     options={"build_exe": {"packages": ["cffi", "cryptography"], "include_files": get_include_files()}},
