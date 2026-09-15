-- FCL 0.7 changed the octree class from the OcTreed alias to the template
-- class fcl::OcTree<double>. Map the Cython OcTreed wrapper to the real
-- C++ template name so the wrapper compiles against FCL 0.7.

--- src/fcl/fcl_defs.pxd.orig	2026-04-08 04:49:56 UTC
+++ src/fcl/fcl_defs.pxd
@@ -402,7 +402,7 @@ cdef extern from "fcl/geometry/octree/octree.h" namesp
 
 
 cdef extern from "fcl/geometry/octree/octree.h" namespace "fcl":
-    cdef cppclass OcTreed(CollisionGeometryd):
+    cdef cppclass OcTreed "fcl::OcTree<double>"(CollisionGeometryd):
         # Constructing
         OcTreed(double resolution) except +
         OcTreed(shared_ptr[octomap.OcTree]& tree_) except +
