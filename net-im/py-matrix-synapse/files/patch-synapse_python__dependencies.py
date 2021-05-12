--- synapse/python_dependencies.py.orig	2021-05-12 14:24:09 UTC
+++ synapse/python_dependencies.py
@@ -86,7 +86,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.7.4",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
 ]
 
 CONDITIONAL_REQUIREMENTS = {
