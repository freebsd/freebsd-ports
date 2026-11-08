-- Replace nose.tools.assert_raises with unittest.TestCase.assertRaises so yt tests can run under Python 3.12 where nose is broken.
--- yt/data_objects/tests/test_particle_filter.py.orig	2026-08-04 00:34:29 UTC
+++ yt/data_objects/tests/test_particle_filter.py
@@ -3,7 +3,8 @@ import numpy as np
 import tempfile
 
 import numpy as np
-from nose.tools import assert_raises
+from unittest import TestCase
+_assert_raises = TestCase().assertRaises
 from numpy.testing import assert_equal
 
 from yt.data_objects.particle_filters import add_particle_filter, particle_filter
@@ -39,7 +40,7 @@ def test_add_particle_filter():
     assert ("deposit", "stars2_cic") in ds.derived_field_list
 
     # Test adding filter with fields not defined on the ds
-    with assert_raises(YTIllDefinedParticleFilter) as ex:
+    with _assert_raises(YTIllDefinedParticleFilter) as ex:
         add_particle_filter(
             "bad_stars", function=stars, filtered_type="all", requires=["wrong_field"]
         )
@@ -131,7 +132,7 @@ def test_particle_filter_exceptions():
     ds.add_particle_filter("filter1")
 
     ad = ds.all_data()
-    with assert_raises(YTIllDefinedFilter):
+    with _assert_raises(YTIllDefinedFilter):
         ad["filter1", "particle_mass"].shape[0]
 
     @particle_filter(filtered_type="all", requires=["particle_mass"])
