Disable some python-2.x code with invalid syntax in python-3.x.

--- readability/compat/two.py.orig	2020-07-03 23:38:42 UTC
+++ readability/compat/two.py
@@ -2,5 +2,5 @@ def raise_with_traceback(exc_type, traceback, *args, *
     """
     Raise a new exception of type `exc_type` with an existing `traceback`. All
     additional (keyword-)arguments are forwarded to `exc_type`
-    """
     raise exc_type(*args, **kwargs), None, traceback
+    """
