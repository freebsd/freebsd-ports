-- Replace deprecated np.int with builtin int for NumPy 1.24+ compatibility.
-- np.int was removed in NumPy 1.24.
--- klusta/utils.py.orig	2026-06-27 16:21:19 UTC
+++ klusta/utils.py
@@ -75,7 +75,7 @@ def _index_of(arr, lookup):
     # values
     lookup = np.asarray(lookup, dtype=np.int32)
     m = (lookup.max() if len(lookup) else 0) + 1
-    tmp = np.zeros(m + 1, dtype=np.int)
+    tmp = np.zeros(m + 1, dtype=int)
     # Ensure that -1 values are kept.
     tmp[-1] = -1
     if len(lookup):
