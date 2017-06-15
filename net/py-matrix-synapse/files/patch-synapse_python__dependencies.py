--- synapse/python_dependencies.py.orig	2017-01-17 17:50:56 UTC
+++ synapse/python_dependencies.py
@@ -22,7 +22,7 @@ REQUIREMENTS = {
     "unpaddedbase64>=1.1.0": ["unpaddedbase64>=1.1.0"],
     "canonicaljson>=1.0.0": ["canonicaljson>=1.0.0"],
     "signedjson>=1.0.0": ["signedjson>=1.0.0"],
-    "pynacl==0.3.0": ["nacl==0.3.0", "nacl.bindings"],
+    "pynacl>=0.3.0": ["nacl>=0.3.0", "nacl.bindings"],
     "service_identity>=1.0.0": ["service_identity>=1.0.0"],
     "Twisted>=15.1.0": ["twisted>=15.1.0"],
     "pyopenssl>=0.14": ["OpenSSL>=0.14"],
