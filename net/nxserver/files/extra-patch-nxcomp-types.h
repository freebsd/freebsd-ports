--- nxcomp/Types.h.orig	Sat Feb  5 15:56:14 2005
+++ nxcomp/Types.h	Tue Mar 29 09:52:13 2005
@@ -74,11 +74,11 @@
 
   void clear()
   {
-    #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H)
+    #if defined(__STL_USE_STD_ALLOCATORS) || defined(_VECTOR_H)
 
-    #if defined(__GLIBCPP_INTERNAL_VECTOR_H)
+    #if defined(_VECTOR_H)
 
-    _Destroy(_M_start, _M_finish);
+    _Destroy(_M_impl._M_start, _M_impl._M_finish);
 
     #else /* #if defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
@@ -86,9 +86,9 @@
 
     #endif /* #if defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
-    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
+    _M_deallocate(_M_impl._M_start, _M_impl._M_end_of_storage - _M_impl._M_start);
 
-    _M_start = _M_finish = _M_end_of_storage = 0;
+    _M_impl._M_start = _M_impl._M_finish = _M_impl._M_end_of_storage = 0;
 
     #else /* #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
@@ -120,21 +120,21 @@
 
   void clear()
   {
-    #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H)
+    #if defined(__STL_USE_STD_ALLOCATORS) || defined(_VECTOR_H)
 
-    #if defined(__GLIBCPP_INTERNAL_VECTOR_H)
+    #if defined(_VECTOR_H)
 
-    _Destroy(_M_start, _M_finish);
+    _Destroy(_M_impl._M_start, _M_impl._M_finish);
 
     #else /* #if defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
-    destroy(_M_start, _M_finish);
+    destroy(_M_impl._M_start, _M_impl._M_finish);
 
     #endif /* #if defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
-    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
+    _M_deallocate(_M_impl._M_start, _M_impl._M_end_of_storage - _M_impl._M_start);
 
-    _M_start = _M_finish = _M_end_of_storage = 0;
+    _M_impl._M_start = _M_impl._M_finish = _M_impl._M_end_of_storage = 0;
 
     #else /* #if defined(__STL_USE_STD_ALLOCATORS) || defined(__GLIBCPP_INTERNAL_VECTOR_H) */
 
