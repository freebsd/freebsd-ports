--- iocage_lib/ioc_common.py.orig	2024-07-10 17:23:47 UTC
+++ iocage_lib/ioc_common.py
@@ -77,7 +77,7 @@ def callback(_log, callback_exception):
         else:
             if not isinstance(message, str) and isinstance(
                 message,
-                collections.Iterable
+                collections.abc.Iterable
             ):
                 message = '\n'.join(message)
 
