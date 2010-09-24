--- ./libs/libFreeMat/Math.cpp.orig	2009-10-09 02:24:22.000000000 -0400
+++ ./libs/libFreeMat/Math.cpp	2010-09-21 14:32:02.000000000 -0400
@@ -1590,9 +1590,9 @@
 
 Array Not(const Array& A) {
   if (A.isScalar())
-    return Array::Array(!A.toClass(Bool).constRealScalar<bool>());
+    return Array(!A.toClass(Bool).constRealScalar<bool>());
   const Array &Abool(A.toClass(Bool));
-  return Array::Array(Apply(Abool.constReal<bool>(),notfunc));
+  return Array(Apply(Abool.constReal<bool>(),notfunc));
 }
 
 Array Plus(const Array& A) {
