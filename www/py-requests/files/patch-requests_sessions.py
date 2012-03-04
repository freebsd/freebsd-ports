--- requests/sessions.py.orig	2011-12-28 10:51:45.000000000 +0100
+++ requests/sessions.py	2012-01-12 23:30:39.000000000 +0100
@@ -13,7 +13,7 @@
 from .models import Request
 from .hooks import dispatch_hook
 from .utils import header_expand
-from .packages.urllib3.poolmanager import PoolManager
+from urllib3.poolmanager import PoolManager
 
 
 def merge_kwargs(local_kwarg, default_kwarg):
