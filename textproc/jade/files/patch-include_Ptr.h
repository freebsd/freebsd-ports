--- include/Ptr.h.orig	1998-10-07 05:15:50 UTC
+++ include/Ptr.h
@@ -5,6 +5,7 @@
 #define Ptr_INCLUDED 1
 
 #include "Boolean.h"
+#include "Resource.h"
 
 // T must have Resource as a public base class
 // T may be an incomplete type
@@ -69,8 +70,8 @@ class ConstPtr : private Ptr<T> { (public)
   const T *operator->() const { return Ptr<T>::pointer(); }
   const T &operator*() const { return *Ptr<T>::pointer(); }
   void swap(ConstPtr<T> &p) { Ptr<T>::swap(p); }
-  Ptr<T>::isNull;
-  Ptr<T>::clear;
+  using Ptr<T>::isNull;
+  using Ptr<T>::clear;
   Boolean operator==(const Ptr<T> &p) const { return Ptr<T>::operator==(p); }
   Boolean operator!=(const Ptr<T> &p) const { return Ptr<T>::operator!=(p); }
   Boolean operator==(const ConstPtr<T> &p) const {
