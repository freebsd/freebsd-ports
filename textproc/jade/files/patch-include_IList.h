--- include/IList.h.orig	1998-10-07 05:15:50 UTC
+++ include/IList.h
@@ -26,8 +26,8 @@ class IList : private IListBase { (public)
   void swap(IList<T> &list) { IListBase::swap(list); }
   T *head() const { return (T *)IListBase::head(); }
   T *get() { return (T *)IListBase::get(); }
-  IListBase::clear;
-  IListBase::empty;
+  using IListBase::clear;
+  using IListBase::empty;
 friend class IListIter<T>;
 private:
   IList(const IList<T> &);	// undefined
