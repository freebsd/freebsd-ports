--- GG/adobe/move.hpp.orig	2009-04-30 23:51:53.000000000 +0400
+++ GG/adobe/move.hpp	2012-01-27 18:58:44.000000000 +0300
@@ -396,7 +396,7 @@
 O move(I f, I l, O result)
 {
     while (f != l) {
-        *result = move(*f);
+      *result = ::adobe::move(*f);
         ++f; ++result;
     }
     return result;
@@ -490,7 +490,7 @@
 template <typename T, typename U> // T models Regular
 inline void move_construct(T* p, U& x, typename move_sink<U, T>::type = 0)
 {
-    ::new(static_cast<void*>(p)) T(move(x));
+  ::new(static_cast<void*>(p)) T(::adobe::move(x));
 }
 
 /*************************************************************************************************/
