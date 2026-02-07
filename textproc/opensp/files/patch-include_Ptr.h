--- include/Ptr.h.orig	2005-07-21 14:04:39 UTC
+++ include/Ptr.h
@@ -69,8 +69,8 @@ class ConstPtr : private Ptr<T> { (public)
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
