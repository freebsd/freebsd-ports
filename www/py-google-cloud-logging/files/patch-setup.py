--- setup.py.orig	2021-07-28 20:06:37 UTC
+++ setup.py
@@ -33,7 +33,7 @@ dependencies = [
     # Until this issue is closed
     # https://github.com/googleapis/google-cloud-python/issues/10566
     "google-api-core[grpc] >= 1.26.0, <3.0.0dev",
-    "google-cloud-appengine-logging >= 0.1.0, < 1.0.0dev",
+    "google-cloud-appengine-logging >= 0.1.0, < 1.1.1",
     "google-cloud-audit-log >= 0.1.0, < 1.0.0dev",
     # NOTE: Maintainers, please do not require google-api-core>=2.x.x
     # Until this issue is closed
