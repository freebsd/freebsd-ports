-- threadpoolctl is not available/functional on FreeBSD.
-- This patch comments out threadpoolctl import and usage to allow the package
-- to build and run on FreeBSD.
---
--- MDAnalysisTests/transformations/test_base.py.orig	2026-04-29 20:16:20 UTC
+++ MDAnalysisTests/transformations/test_base.py
@@ -22,7 +22,8 @@ from numpy.testing import assert_equal
 import numpy as np
 import pytest
 from numpy.testing import assert_equal
-from threadpoolctl import threadpool_info
+# threadpoolctl is not yet usable on FreeBSD
+#from threadpoolctl import threadpool_info
 
 import MDAnalysis as mda
 from MDAnalysisTests.datafiles import PSF, DCD
@@ -36,7 +37,7 @@ class DefaultTransformation(TransformationBase):
         super().__init__()
 
     def _transform(self, ts):
-        self.runtime_info = threadpool_info()
+        """self.runtime_info = threadpool_info()"""
         ts.positions = ts.positions + 1
         return ts
 
@@ -57,7 +58,7 @@ class CustomTransformation(TransformationBase):
         )
 
     def _transform(self, ts):
-        self.runtime_info = threadpool_info()
+        """self.runtime_info = threadpool_info()"""
         ts.positions = ts.positions + 1
         return ts
