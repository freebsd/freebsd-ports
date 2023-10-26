--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h.orig	2023-07-14 13:25:01 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h
@@ -67,25 +67,21 @@ class CircularQueue {
       ignore_result(generation);
     }
 
-    T* operator->() {
+    Iterator(const Iterator&) noexcept = default;
+    Iterator& operator=(const Iterator&) noexcept = default;
+    Iterator(Iterator&&) noexcept = default;
+    Iterator& operator=(Iterator&&) noexcept = default;
+
+    T* operator->() const {
 #if PERFETTO_DCHECK_IS_ON()
       PERFETTO_DCHECK(generation_ == queue_->generation());
 #endif
       return queue_->Get(pos_);
     }
 
-    const T* operator->() const {
-      return const_cast<CircularQueue<T>::Iterator*>(this)->operator->();
-    }
+    T& operator*() const { return *(operator->()); }
 
-    T& operator*() { return *(operator->()); }
-    const T& operator*() const { return *(operator->()); }
-
     value_type& operator[](difference_type i) { return *(*this + i); }
-
-    const value_type& operator[](difference_type i) const {
-      return const_cast<CircularQueue<T>::Iterator&>(*this)[i];
-    }
 
     Iterator& operator++() {
       Add(1);
