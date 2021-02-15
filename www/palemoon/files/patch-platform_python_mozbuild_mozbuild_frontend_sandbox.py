--- platform/python/mozbuild/mozbuild/frontend/sandbox.py.orig	2021-02-05 18:43:01 UTC
+++ platform/python/mozbuild/mozbuild/frontend/sandbox.py
@@ -115,7 +115,10 @@ class Sandbox(dict):
     def __init__(self, context, builtins=None, finder=default_finder):
         """Initialize a Sandbox ready for execution.
         """
-        self._builtins = builtins or self.BUILTINS
+        self._builtins = ReadOnlyDict(
+            (builtins or self.BUILTINS).viewitems() |
+            {b: __builtins__[b] for b in ('__build_class__',)
+             if b in __builtins__}.viewitems())
         dict.__setitem__(self, '__builtins__', self._builtins)
 
         assert isinstance(self._builtins, ReadOnlyDict)
