--- iocage_lib/ioc_exceptions.py.orig	2024-07-10 17:22:46 UTC
+++ iocage_lib/ioc_exceptions.py
@@ -31,7 +31,7 @@ class ExceptionWithMsg(Exception):
     def __init__(self, message):
         if not isinstance(message, str) and not isinstance(
             message,
-            collections.Iterable
+            collections.abc.Iterable
         ):
             message = [message]
 
