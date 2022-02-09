--- synapse/python_dependencies.py.orig	2022-02-08 11:47:35 UTC
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
@@ -77,7 +77,7 @@ REQUIREMENTS = [
     "phonenumbers>=8.2.0",
     # we use GaugeHistogramMetric, which was added in prom-client 0.4.0.
     # 0.13.0 has an incorrect type annotation, see #11832.
-    "prometheus_client>=0.4.0,<0.13.0",
+    "prometheus_client>=0.4.0",
     # we use `order`, which arrived in attrs 19.2.0.
     # Note: 21.1.0 broke `/sync`, see #9936
     "attrs>=19.2.0,!=21.1.0",
@@ -87,7 +87,7 @@ REQUIREMENTS = [
     "typing-extensions>=3.7.4",
     # We enforce that we have a `cryptography` version that bundles an `openssl`
     # with the latest security patches.
-    "cryptography>=3.4.7",
+    "cryptography",
     "ijson>=3.1",
     "matrix-common==1.0.0",
 ]
