--- src/common/bounded_key_counter.h.orig	2018-02-26 21:47:18 UTC
+++ src/common/bounded_key_counter.h
@@ -73,7 +73,11 @@ class BoundedKeyCounter {
   struct const_pointer_iterator : public map_type::const_iterator {
     const_pointer_iterator(typename map_type::const_iterator i)
       : map_type::const_iterator(i) {}
-    const value_type* operator*() const {
+
+    using value_type = typename map_type::const_iterator::value_type*;
+    using reference = const typename map_type::const_iterator::value_type*;
+
+    reference operator*() const {
       return &map_type::const_iterator::operator*();
     }
   };
