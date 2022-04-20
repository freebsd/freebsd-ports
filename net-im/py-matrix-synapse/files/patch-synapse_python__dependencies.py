--- synapse/python_dependencies.py.orig	2022-04-20 00:17:17 UTC
+++ synapse/python_dependencies.py
@@ -82,7 +82,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.10.0",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
     # ijson 3.1.4 fixes a bug with "." in property names
     "ijson>=3.1.4",
     "matrix-common~=1.1.0",
