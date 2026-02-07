--- salt/modules/config.py.orig	2025-01-17 15:15:13 UTC
+++ salt/modules/config.py
@@ -17,13 +17,7 @@ from salt.loader.context import LoaderContext
 import salt.utils.sdb as sdb
 from salt.loader.context import LoaderContext
 
-try:
-    # Gated for salt-ssh (salt.utils.cloud imports msgpack)
-    import salt.utils.cloud
-
-    HAS_CLOUD = True
-except ImportError:
-    HAS_CLOUD = False
+HAS_CLOUD = False
 
 
 if salt.utils.platform.is_windows():
