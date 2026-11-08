-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/data_objects/tests/test_dataset_access.py.orig	2026-08-04 00:34:29 UTC
+++ yt/data_objects/tests/test_dataset_access.py
@@ -1,5 +1,6 @@ import numpy as np
 import numpy as np
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_almost_equal, assert_equal
 
 from yt.testing import (
@@ -66,7 +67,7 @@ def test_region_from_d():
     assert_equal(reg1["gas", "density"], reg2["gas", "density"])
 
     # Test with bad boundary initialization
-    with assert_raises(RuntimeError):
+    with _assert_raises(RuntimeError):
         ds.r[0.3:0.1, 0.4:0.6, :]
 
     # Test region by creating an arbitrary grid
@@ -133,7 +134,7 @@ def test_point_from_r():
     assert_equal(pt1["gas", "density"], pt2["gas", "density"])
 
     # Test YTDimensionalityError
-    with assert_raises(YTDimensionalityError) as ex:
+    with _assert_raises(YTDimensionalityError) as ex:
         ds.r[0.5, 0.1]
     assert_equal(str(ex.exception), "Dimensionality specified was 2 but we need 3")
 
