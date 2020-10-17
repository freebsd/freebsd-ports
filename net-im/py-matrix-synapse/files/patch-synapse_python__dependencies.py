--- synapse/python_dependencies.py.orig	2020-10-15 15:59:57 UTC
+++ synapse/python_dependencies.py
@@ -72,7 +72,7 @@ REQUIREMENTS = [
     # prom-client has a history of breaking backwards compatibility between
     # minor versions (https://github.com/prometheus/client_python/issues/317),
     # so we also pin the minor version.
-    "prometheus_client>=0.4.0,<0.9.0",
+    "prometheus_client>=0.4.0",
     # we use attr.validators.deep_iterable, which arrived in 19.1.0 (Note:
     # Fedora 31 only has 19.1, so if we want to upgrade we should wait until 33
     # is out in November.)
