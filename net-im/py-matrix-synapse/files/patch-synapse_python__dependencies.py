--- synapse/python_dependencies.py.orig	2020-11-18 13:34:04 UTC
+++ synapse/python_dependencies.py
@@ -76,7 +76,7 @@ REQUIREMENTS = [
     # Note that we replicate these constraints in the Synapse Dockerfile while
     # pre-installing dependencies. If these constraints are updated here, the
     # same change should be made in the Dockerfile.
-    "prometheus_client>=0.4.0,<0.9.0",
+    "prometheus_client>=0.4.0",
     # we use attr.validators.deep_iterable, which arrived in 19.1.0 (Note:
     # Fedora 31 only has 19.1, so if we want to upgrade we should wait until 33
     # is out in November.)
