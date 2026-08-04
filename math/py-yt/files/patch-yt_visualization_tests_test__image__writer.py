-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/visualization/tests/test_image_writer.py.orig	2026-08-04 00:34:29 UTC
+++ yt/visualization/tests/test_image_writer.py
@@ -4,7 +4,8 @@ import numpy as np
 import unittest
 
 import numpy as np
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_equal
 
 from yt.testing import fake_random_ds
@@ -65,7 +66,7 @@ class TestImageWriter(unittest.TestCase):
         png_str_trans = write_bitmap(image_trans, None, transpose=True)
         assert_equal(png_str, png_str_trans)
 
-        with assert_raises(RuntimeError) as ex:
+        with _assert_raises(RuntimeError) as ex:
             write_bitmap(np.ones([16, 16]), None)
         desired = "Expecting image array of shape (N,M,3) or (N,M,4), received (16, 16)"
         assert_equal(str(ex.exception)[:50], desired[:50])
