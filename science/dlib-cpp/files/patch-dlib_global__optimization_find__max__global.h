--- dlib/global_optimization/find_max_global.h.orig	2022-05-08 14:35:36 UTC
+++ dlib/global_optimization/find_max_global.h
@@ -58,7 +58,7 @@ namespace dlib
             }
 
             template <typename T>
-            static auto go(T&& f, const matrix<double,0,1>& a) -> decltype(call_function_and_expand_args<max_unpack-1>::template go(std::forward<T>(f),a))
+            static auto go(T&& f, const matrix<double,0,1>& a) -> decltype(call_function_and_expand_args<max_unpack-1>::template go<>(std::forward<T>(f),a))
             {
                 return call_function_and_expand_args<max_unpack-1>::go(std::forward<T>(f),a);
             }
