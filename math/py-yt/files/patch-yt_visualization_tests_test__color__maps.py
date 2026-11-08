-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/visualization/tests/test_color_maps.py.orig	2026-08-04 00:34:29 UTC
+++ yt/visualization/tests/test_color_maps.py
@@ -5,7 +5,8 @@ import numpy as np
 
 import matplotlib.pyplot as plt
 import numpy as np
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_almost_equal, assert_equal
 
 from yt import make_colormap, show_colormaps
@@ -29,7 +30,7 @@ class TestColorMaps(unittest.TestCase):
         show_colormaps(subset="yt_native", filename="yt_color_maps.png")
 
         # Test for non-existent color map
-        with assert_raises(AttributeError) as ex:
+        with _assert_raises(AttributeError) as ex:
             show_colormaps(subset="unknown", filename="yt_color_maps.png")
         desired = (
             "show_colormaps requires subset attribute to be 'all', "
