--- synapse/python_dependencies.py.orig	2019-07-25 21:31:46.581498307 +0200
+++ synapse/python_dependencies.py	2019-07-25 21:31:57.254468848 +0200
@@ -65,7 +65,7 @@
     "msgpack>=0.5.2",
     "phonenumbers>=8.2.0",
     "six>=1.10",
-    "prometheus_client>=0.0.18,<0.8.0",
+    "prometheus_client>=0.0.18",
     # we use attr.s(slots), which arrived in 16.0.0
     # Twisted 18.7.0 requires attrs>=17.4.0
     "attrs>=17.4.0",
