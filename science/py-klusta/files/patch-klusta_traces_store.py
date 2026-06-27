-- Replace deprecated np.object with builtin object for NumPy 1.24+ compatibility.
-- np.object was removed in NumPy 1.24.
--- klusta/traces/store.py.orig	2026-06-27 16:21:19 UTC
+++ klusta/traces/store.py
@@ -97,7 +97,7 @@ class ArrayStore(object):
             dtype = data.dtype
             if not data.size:
                 return
-            assert dtype != np.object
+            assert dtype != object
             np.save(path, data)
         # debug("Store {}.".format(path))
 
