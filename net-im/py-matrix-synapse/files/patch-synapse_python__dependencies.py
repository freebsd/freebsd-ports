--- synapse/python_dependencies.py.orig	2022-04-12 08:11:46 UTC
+++ synapse/python_dependencies.py
@@ -48,7 +48,7 @@ REQUIREMENTS = [
     "unpaddedbase64>=1.1.0",
     "canonicaljson>=1.4.0",
     # we use the type definitions added in signedjson 1.1.
-    "signedjson>=1.1.0,<=1.1.1",
+    "signedjson>=1.1.0",
     "pynacl>=1.2.1",
     "idna>=2.5",
     # validating SSL certs for IP addresses requires service_identity 18.1.
@@ -83,7 +83,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.10.0",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
     # ijson 3.1.4 fixes a bug with "." in property names
     "ijson>=3.1.4",
     "matrix-common~=1.1.0",
