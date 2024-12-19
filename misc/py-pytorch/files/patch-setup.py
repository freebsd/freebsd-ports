--- setup.py.orig	2024-12-19 06:28:23 UTC
+++ setup.py
@@ -1144,7 +1144,7 @@ def main():
         "typing-extensions>=4.8.0",
         'setuptools ; python_version >= "3.12"',
         'sympy==1.12.1 ; python_version == "3.8"',
-        'sympy==1.13.1 ; python_version >= "3.9"',
+        'sympy; python_version >= "3.9"',
         "networkx",
         "jinja2",
         "fsspec",
