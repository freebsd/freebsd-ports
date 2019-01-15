--- synapse/python_dependencies.py.orig	2019-01-10 17:51:27.362204447 +0100
+++ synapse/python_dependencies.py	2019-01-10 17:51:47.559224870 +0100
@@ -58,7 +58,7 @@
     "six>=1.10",
     # prometheus_client 0.4.0 changed the format of counter metrics
     # (cf https://github.com/matrix-org/synapse/issues/4001)
-    "prometheus_client>=0.0.18,<0.4.0",
+    "prometheus_client>=0.0.18",
     # we use attr.s(slots), which arrived in 16.0.0
     "attrs>=16.0.0",
     "netaddr>=0.7.18",
