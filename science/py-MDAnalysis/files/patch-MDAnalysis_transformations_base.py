--- MDAnalysis/transformations/base.py.orig	2022-06-02 18:49:09 UTC
+++ MDAnalysis/transformations/base.py
@@ -26,8 +26,9 @@ Transformations Base Class --- :mod:`MDAnalysis.transf
 
 .. autoclass:: TransformationBase
 
-"""
+Note: threadpoolctl does not yet run on FreeBSD
 from threadpoolctl import threadpool_limits
+"""
 
 
 class TransformationBase(object):
@@ -113,8 +114,7 @@ class TransformationBase(object):
         The thread limit works as a context manager with given `max_threads`
         wrapping the real :func:`_transform` function
         """
-        with threadpool_limits(self.max_threads):
-            return self._transform(ts)
+        return self._transform(ts)
 
     def _transform(self, ts):
         """Transform the given `Timestep`
