--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h
@@ -67,6 +67,11 @@ class CircularQueue {
       ignore_result(generation);
     }
 
+    Iterator(const Iterator&) noexcept = default;
+    Iterator& operator=(const Iterator&) noexcept = default;
+    Iterator(Iterator&&) noexcept = default;
+    Iterator& operator=(Iterator&&) noexcept = default;
+
     T* operator->() const {
 #if PERFETTO_DCHECK_IS_ON()
       PERFETTO_DCHECK(generation_ == queue_->generation());
@@ -77,10 +82,6 @@ class CircularQueue {
     T& operator*() const { return *(operator->()); }
 
     value_type& operator[](difference_type i) { return *(*this + i); }
-
-    const value_type& operator[](difference_type i) const {
-      return const_cast<CircularQueue<T>::Iterator&>(*this)[i];
-    }
 
     Iterator& operator++() {
       Add(1);
