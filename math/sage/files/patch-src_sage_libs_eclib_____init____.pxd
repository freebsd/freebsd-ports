--- src/sage/libs/eclib/__init__.pxd.orig	2021-03-16 21:40:43 UTC
+++ src/sage/libs/eclib/__init__.pxd
@@ -8,9 +8,11 @@ from libcpp.pair cimport pair
 from sage.libs.ntl.types cimport ZZ_c
 
 
-# NOTE: eclib includes have specific dependencies and must be included
-# in a specific order. So we start by listing all relevant include files
-# in the correct order.
+# NOTE: eclib used to have specific dependencies, so that they had to
+# be included in a specific order. Although this is no longer the
+# case, we start by listing all relevant include files in the correct
+# order.
+
 cdef extern from "eclib/vector.h": pass
 cdef extern from "eclib/xmod.h": pass
 cdef extern from "eclib/svector.h": pass
