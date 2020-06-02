--- base/stl_util.h.orig	2020-05-18 14:07:28 UTC
+++ base/stl_util.h
@@ -561,14 +561,6 @@ size_t EraseIf(std::vector<T, Allocator>& container, P
   return removed;
 }
 
-template <class T, class Allocator, class Value>
-size_t Erase(std::forward_list<T, Allocator>& container, const Value& value) {
-  // Unlike std::forward_list::remove, this function template accepts
-  // heterogeneous types and does not force a conversion to the container's
-  // value type before invoking the == operator.
-  return EraseIf(container, [&](const T& cur) { return cur == value; });
-}
-
 template <class T, class Allocator, class Predicate>
 size_t EraseIf(std::forward_list<T, Allocator>& container, Predicate pred) {
   // Note: std::forward_list does not have a size() API, thus we need to use the
@@ -580,10 +572,10 @@ size_t EraseIf(std::forward_list<T, Allocator>& contai
 }
 
 template <class T, class Allocator, class Value>
-size_t Erase(std::list<T, Allocator>& container, const Value& value) {
-  // Unlike std::list::remove, this function template accepts heterogeneous
-  // types and does not force a conversion to the container's value type before
-  // invoking the == operator.
+size_t Erase(std::forward_list<T, Allocator>& container, const Value& value) {
+  // Unlike std::forward_list::remove, this function template accepts
+  // heterogeneous types and does not force a conversion to the container's
+  // value type before invoking the == operator.
   return EraseIf(container, [&](const T& cur) { return cur == value; });
 }
 
@@ -592,6 +584,14 @@ size_t EraseIf(std::list<T, Allocator>& container, Pre
   size_t old_size = container.size();
   container.remove_if(pred);
   return old_size - container.size();
+}
+
+template <class T, class Allocator, class Value>
+size_t Erase(std::list<T, Allocator>& container, const Value& value) {
+  // Unlike std::list::remove, this function template accepts heterogeneous
+  // types and does not force a conversion to the container's value type before
+  // invoking the == operator.
+  return EraseIf(container, [&](const T& cur) { return cur == value; });
 }
 
 template <class Key, class T, class Compare, class Allocator, class Predicate>
