--- GG/adobe/any_regular.hpp.orig	2011-01-04 06:58:05.000000000 +0300
+++ GG/adobe/any_regular.hpp	2012-01-27 19:05:34.000000000 +0300
@@ -220,7 +220,7 @@
     
     template <typename U>
     explicit any_regular_model_local(U x, typename move_sink<U, T>::type = 0)
-        : interface_type(vtable_s), object_m(move(x)) { }
+      : interface_type(vtable_s), object_m(::adobe::move(x)) { }
         
     static const any_regular_model_local& self(const interface_type& x)
     { return static_cast<const any_regular_model_local&>(x); }
@@ -238,7 +238,7 @@
     { return ::new(storage) any_regular_model_local(self(x).object_m); }
     
     static interface_type* move_clone(interface_type& x, void* storage)
-    { return ::new(storage) any_regular_model_local(move(self(x).object_m)); }
+  { return ::new(storage) any_regular_model_local(::adobe::move(self(x).object_m)); }
     
     static void assign(interface_type& x, const interface_type& y)
     { self(x).object_m = self(y).object_m; }
@@ -552,7 +552,7 @@
     
     template <typename T>
     explicit any_regular_t(T x, typename move_sink<T>::type = 0) : data_ptr_m(&data_m[0])
-    { ::new (storage()) typename traits<T>::model_type(move(x)); }
+  { ::new (storage()) typename traits<T>::model_type(::adobe::move(x)); }
     
     /*!@}*/
     
