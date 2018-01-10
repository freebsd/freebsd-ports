--- include/IListIter.h.orig	1998-10-07 05:15:50 UTC
+++ include/IListIter.h
@@ -17,8 +17,8 @@ class IListIter : private IListIterBase { (public)
   IListIter(const IList<T> &list) : IListIterBase(list) { }
   T *cur() const { return (T *)IListIterBase::cur(); }
   
-  IListIterBase::next;
-  IListIterBase::done;
+  using IListIterBase::next;
+  using IListIterBase::done;
 };
 
 #ifdef SP_NAMESPACE
