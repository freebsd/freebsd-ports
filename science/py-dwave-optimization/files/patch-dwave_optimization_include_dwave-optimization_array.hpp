--- dwave/optimization/include/dwave-optimization/array.hpp.orig	2026-07-27 22:30:07 UTC
+++ dwave/optimization/include/dwave-optimization/array.hpp
@@ -371,6 +371,7 @@ class Array {
 /// the Array::dynamic() method is provided.
 class Array {
  public:
+    virtual ~Array();
     /// A std::random_access_iterator over the values in the array.
     using iterator = BufferIterator<double, double>;
 
