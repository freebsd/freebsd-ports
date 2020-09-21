--- synapse/python_dependencies.py.orig	2020-07-15 20:12:36 UTC
+++ synapse/python_dependencies.py
@@ -66,7 +66,7 @@ REQUIREMENTS = [
     "pymacaroons>=0.13.0",
     "msgpack>=0.5.2",
     "phonenumbers>=8.2.0",
-    "prometheus_client>=0.0.18,<0.9.0",
+    "prometheus_client>=0.0.18",
     # we use attr.validators.deep_iterable, which arrived in 19.1.0
     "attrs>=19.1.0",
     "netaddr>=0.7.18",
