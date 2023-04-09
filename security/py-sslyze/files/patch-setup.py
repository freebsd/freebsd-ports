--- setup.py.orig	2023-04-01 13:24:09 UTC
+++ setup.py
@@ -102,7 +102,7 @@ setup(
         "cryptography>=2.6,<40",
         "tls-parser>=2,<3",
         "pydantic>=1.7,<1.11",
-        "pyOpenSSL>=23,<24",
+        "pyOpenSSL>=20,<24",
     ],
     # cx_freeze info for Windows builds with Python embedded
     options={"build_exe": {"packages": ["cffi", "cryptography"], "include_files": get_include_files()}},
