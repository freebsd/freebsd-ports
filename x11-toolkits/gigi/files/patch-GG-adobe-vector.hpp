--- GG/adobe/vector.hpp.orig	2012-01-27 18:38:56.000000000 +0300
+++ GG/adobe/vector.hpp	2012-01-27 18:40:58.000000000 +0300
@@ -343,7 +343,7 @@
     size_type n(std::distance(f, l));
     
         if (remaining() < n) reserve((adobe::max)(size() + n, 2 * size()));
-    set_finish(uninitialized_move(f, l, end()));
+        set_finish(::adobe::uninitialized_move(f, l, end()));
 }
     
 template <typename T, typename A>
@@ -430,7 +430,7 @@
     if (capacity() < n) {
         vector tmp;
         tmp.header_m = allocate(get_allocator(), n);
-        tmp.header_m->finish() = uninitialized_move(begin(), end(), tmp.end());
+        tmp.header_m->finish() = ::adobe::uninitialized_move(begin(), end(), tmp.end());
         swap(tmp);
     }
 }
@@ -469,7 +469,7 @@
 template <typename T, typename A>
 typename vector<T, A>::iterator vector<T, A>::erase(iterator f, iterator l)
 {
-    iterator i = move(l, end(), f);
+  iterator i = ::adobe::move(l, end(), f);
     for (iterator b(i), e(end()); b != e; ++b) {
         b->~value_type();
     }
