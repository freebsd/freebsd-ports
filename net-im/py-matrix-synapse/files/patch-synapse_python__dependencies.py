--- synapse/python_dependencies.py.orig	2021-04-07 20:22:25 UTC
+++ synapse/python_dependencies.py
@@ -85,7 +85,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.7.4",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7;python_version>='3.6'",
+    #"cryptography>=3.4.7;python_version>='3.6'",
 ]
 
 CONDITIONAL_REQUIREMENTS = {
