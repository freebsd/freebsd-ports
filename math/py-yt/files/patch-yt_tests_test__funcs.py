-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/tests/test_funcs.py.orig	2026-08-04 00:34:29 UTC
+++ yt/tests/test_funcs.py
@@ -1,6 +1,7 @@ import os
 import os
 
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_equal
 
 from yt.funcs import (
@@ -21,7 +22,7 @@ def test_validate_axis():
     ds = fake_amr_ds(geometry="cylindrical")
     ds.slice("Theta", 0.25)
 
-    with assert_raises(TypeError) as ex:
+    with _assert_raises(TypeError) as ex:
         # default geometry is cartesian
         ds = fake_amr_ds()
         ds.slice("r", 0.25)
@@ -35,7 +36,7 @@ def test_validate_center():
     validate_center("max")
     validate_center("MIN_")
 
-    with assert_raises(TypeError) as ex:
+    with _assert_raises(TypeError) as ex:
         validate_center("avg")
     desired = (
         "Expected 'center' to be in ['c', 'center', 'm', 'max', 'min'] "
@@ -50,7 +51,7 @@ def test_validate_center():
         def __init__(self, center):
             self.center = center
 
-    with assert_raises(TypeError) as ex:
+    with _assert_raises(TypeError) as ex:
         validate_center(CustomCenter(10))
     desired = (
         "Expected 'center' to be a numeric object of type "
@@ -118,7 +119,7 @@ def test_simple_download_file():
         except FileNotFoundError:
             pass
 
-    with assert_raises(RuntimeError) as ex:
+    with _assert_raises(RuntimeError) as ex:
         simple_download_file("http://yt-project.org/404", "simple-download-file")
 
     desired = "Attempt to download file from http://yt-project.org/404 failed with error 404: Not Found."
