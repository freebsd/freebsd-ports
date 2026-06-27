-- Replace deprecated np.int with builtin int for NumPy 1.24+ compatibility.
-- np.int was removed in NumPy 1.24.
--- klusta/traces/tests/test_spikedetekt.py.orig	2026-06-27 16:21:19 UTC
+++ klusta/traces/tests/test_spikedetekt.py
@@ -46,7 +46,7 @@ def test_split_spikes():
 
 
 def test_split_spikes():
-    groups = np.zeros(10, dtype=np.int)
+    groups = np.zeros(10, dtype=int)
     groups[1::2] = 1
 
     idx = np.ones(10, dtype=np.bool)
