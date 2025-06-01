--- setup.py.orig	2025-05-21 18:00:57 UTC
+++ setup.py
@@ -20,7 +20,7 @@ DEPENDENCIES = (
 
 
 DEPENDENCIES = (
-    "cachetools>=2.0.0,<6.0",
+    "cachetools>=2.0.0",
     "pyasn1-modules>=0.2.1",
     # rsa==4.5 is the last version to support 2.7
     # https://github.com/sybrenstuvel/python-rsa/issues/152#issuecomment-643470233
