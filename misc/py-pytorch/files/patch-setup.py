--- setup.py.orig	2025-03-18 16:43:41 UTC
+++ setup.py
@@ -1099,7 +1099,7 @@ def main():
         "filelock",
         "typing-extensions>=4.10.0",
         'setuptools ; python_version >= "3.12"',
-        'sympy==1.13.1 ; python_version >= "3.9"',
+        'sympy>=1.13.1 ; python_version >= "3.9"',
         "networkx",
         "jinja2",
         "fsspec",
