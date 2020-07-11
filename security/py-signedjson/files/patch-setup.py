Obtained from:  https://github.com/matrix-org/python-signedjson/commit/c40c83f844fee3c1c7b0c5d1508f87052334b4e5

--- setup.py.orig	2020-03-27 19:41:34 UTC
+++ setup.py
@@ -41,7 +41,7 @@ setup(
         "pynacl>=0.3.0",
         "typing_extensions>=3.5",
         'typing>=3.5;python_version<"3.5"',
-        "importlib_metadata",
+        'importlib_metadata;python_version<"3.8"',
     ],
     long_description=read_file(("README.rst",)),
     keywords="json",
