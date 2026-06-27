-- Fix np.linspace() call: the 'num' parameter must be an integer in NumPy 2.x.
-- The test used rate=10000. (float) which causes TypeError in NumPy 2.x.
--- klusta/traces/tests/test_filter.py.orig	2026-06-27 16:23:43 UTC
+++ klusta/traces/tests/test_filter.py
@@ -20,7 +20,7 @@ def test_apply_filter():
 def test_apply_filter():
     """Test bandpass filtering on a combination of two sinusoids."""
 
-    rate = 10000.
+    rate = 10000
     low, high = 100., 200.
 
     # Create a signal with small and high frequencies.
