--- include/Ptr.h.orig	Wed Oct  7 14:15:50 1998
+++ include/Ptr.h	Tue Jul 22 09:19:49 2003
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
