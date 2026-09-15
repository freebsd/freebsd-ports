-- Skip signed-distance tests because they trigger an infinite loop in upstream
-- FCL's libccd signed-distance code on FreeBSD.
-- See https://github.com/flexible-collision-library/fcl/issues/578

--- tests/test_precision.py.orig	2026-09-15 22:26:08 UTC
+++ tests/test_precision.py
@@ -127,6 +127,7 @@ class TestPrecision(unittest.TestCase):
         ret = fcl.distance(self.o2, self.o1, request, result)
         assert ret == -1
 
+    @unittest.skip("Upstream FCL signed-distance bug; hangs on FreeBSD")
     def test_obj_obj_signed_distance(self):
         request = fcl.DistanceRequest(
             enable_nearest_points=True, enable_signed_distance=True
@@ -164,6 +165,7 @@ class TestPrecision(unittest.TestCase):
         self.mgr2.collide(self.mgr1, rdata, fcl.defaultCollisionCallback)
         assert rdata.result.is_collision
 
+    @unittest.skip("Upstream FCL signed-distance bug; hangs on FreeBSD")
     def test_mgr_obj_signed_distance(self):
         req = fcl.DistanceRequest(enable_signed_distance=True, enable_nearest_points=True)
         ddata = fcl.DistanceData(req)
@@ -183,6 +185,7 @@ class TestPrecision(unittest.TestCase):
             abs(ddata.result.min_distance),
         )
 
+    @unittest.skip("Upstream FCL signed-distance bug; hangs on FreeBSD")
     def test_mgr_mgr_signed_distance(self):
         req = fcl.DistanceRequest(enable_signed_distance=True, enable_nearest_points=True)
         ddata = fcl.DistanceData(req)
