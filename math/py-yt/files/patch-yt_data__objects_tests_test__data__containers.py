-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/data_objects/tests/test_data_containers.py.orig	2026-08-04 00:34:29 UTC
+++ yt/data_objects/tests/test_data_containers.py
@@ -4,7 +4,8 @@ import numpy as np
 import unittest
 
 import numpy as np
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_array_equal, assert_equal
 
 from yt.data_objects.data_containers import YTDataContainer
@@ -32,7 +33,7 @@ class TestDataContainers(unittest.TestCase):
 
     def test_yt_data_container(self):
         # Test if ds could be None
-        with assert_raises(RuntimeError) as err:
+        with _assert_raises(RuntimeError) as err:
             YTDataContainer(None, None)
         desired = (
             "Error: ds must be set either through class"
@@ -53,7 +54,7 @@ class TestDataContainers(unittest.TestCase):
         assert_equal("density" in proj.keys(), False)
 
         # Delete a non-existent field
-        with assert_raises(YTFieldNotFound) as ex:
+        with _assert_raises(YTFieldNotFound) as ex:
             del proj["p_mass"]
         desired = "Could not find field 'p_mass' in UniformGridData."
         assert_equal(str(ex.exception), desired)
@@ -82,7 +83,7 @@ class TestDataContainers(unittest.TestCase):
         ds = fake_random_ds(16, particles=10)
         sp = ds.sphere(ds.domain_center, 0.25)
 
-        with assert_raises(YTException):
+        with _assert_raises(YTException):
             sp.write_out(filename, fields=[("all", "particle_ones")])
 
     @requires_module("pandas")
@@ -152,7 +153,7 @@ class TestDataContainers(unittest.TestCase):
         dd = ds.all_data()
         q = dd.quantities["WeightedAverageQuantity"]
         rho = q(("all", "particle_velocity_x"), weight=("all", "particle_mass"))
-        with assert_raises(NotImplementedError):
+        with _assert_raises(NotImplementedError):
             dd.extract_isocontours("density", rho, sample_values="x")
 
     def test_derived_field(self):
