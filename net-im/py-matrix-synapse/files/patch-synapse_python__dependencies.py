--- synapse/python_dependencies.py.orig	2022-01-15 14:42:17 UTC
+++ synapse/python_dependencies.py
@@ -51,7 +51,7 @@ REQUIREMENTS = [
     # we use the TYPE_CHECKER.redefine method added in jsonschema 3.0.0
     "jsonschema>=3.0.0",
     # frozendict 2.1.2 is broken on Debian 10: https://github.com/Marco-Sulla/python-frozendict/issues/41
-    "frozendict>=1,<2.1.2",
+    "frozendict>=1",
     "unpaddedbase64>=1.1.0",
     "canonicaljson>=1.4.0",
     # we use the type definitions added in signedjson 1.1.
@@ -86,7 +86,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.7.4",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
     "ijson>=3.1",
 ]
 
