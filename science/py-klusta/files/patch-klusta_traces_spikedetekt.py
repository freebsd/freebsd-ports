-- Replace deprecated np.object with builtin object for NumPy 1.24+ compatibility.
-- np.object was removed in NumPy 1.24.
--- klusta/traces/spikedetekt.py.orig	2026-06-27 16:21:19 UTC
+++ klusta/traces/spikedetekt.py
@@ -69,7 +69,7 @@ def _array_list(arrs):
 
 
 def _array_list(arrs):
-    out = np.empty((len(arrs),), dtype=np.object)
+    out = np.empty((len(arrs),), dtype=object)
     out[:] = arrs
     return out
 
@@ -385,10 +385,10 @@ class SpikeDetekt(object):
         # groups).
         waveforms = _array_list(waveforms)
         assert waveforms.shape == (n_spikes,)
-        assert waveforms.dtype == np.object
+        assert waveforms.dtype == object
 
         masks = _array_list(masks)
-        assert masks.dtype == np.object
+        assert masks.dtype == object
         assert masks.shape == (n_spikes,)
 
         # Reorder the spikes.
