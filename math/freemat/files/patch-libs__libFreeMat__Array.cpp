--- ./libs/libFreeMat/Array.cpp.orig	2009-10-09 02:24:20.000000000 -0400
+++ ./libs/libFreeMat/Array.cpp	2010-09-21 14:32:02.000000000 -0400
@@ -465,7 +465,7 @@
 
 void Array::set(const QString& field, ArrayVector& data) {
   if (isEmpty() && m_type.Class != Struct)
-    *this = Array::Array(Struct);
+    *this = Array(Struct);
   if (m_type.Class != Struct) throw Exception("Unsupported type for A.field=B");
   StructArray &rp(structPtr());
   if (isEmpty()) 
