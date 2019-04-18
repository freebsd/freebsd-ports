--- synapse/python_dependencies.py.orig	2019-02-14 17:20:02.000000000 +0000
+++ synapse/python_dependencies.py	2019-02-28 20:31:10.838648000 +0000
@@ -62,7 +62,7 @@
     "six>=1.10",
     # prometheus_client 0.4.0 changed the format of counter metrics
     # (cf https://github.com/matrix-org/synapse/issues/4001)
-    "prometheus_client>=0.0.18,<0.4.0",
+    "prometheus_client>=0.0.18",
 
     # we use attr.s(slots), which arrived in 16.0.0
     # Twisted 18.7.0 requires attrs>=17.4.0
