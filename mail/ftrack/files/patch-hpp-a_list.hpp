--- hpp/a_list.hpp.orig	Fri Aug 19 17:20:23 2005
+++ hpp/a_list.hpp	Fri Aug 19 17:47:38 2005
@@ -173,8 +173,8 @@
   protected:
 
     class Elem : public AbstractElem {
-        friend BiList<T>;
-        friend ElemPtr;
+        friend class BiList<T>;
+        friend class ElemPtr;
       public:
         T data;
         operator T&() { return data; }
@@ -199,7 +199,7 @@
   public:
 
     class ElemPtr {
-        friend BiList<T>;
+        friend class BiList<T>;
         Elem *p;
         ElemPtr(Elem *e) { p = e; }
       protected:
@@ -294,8 +294,8 @@
   public:
   class ElemPtr : public BiList<T>::ElemPtr {
     public:
-    ElemPtr(BiList<T>::ElemPtr &e) : BiList<T>::ElemPtr(e){}
-    T* operator->() { return operator T*(); }
+    ElemPtr(typename BiList<T>::ElemPtr &e) : BiList<T>::ElemPtr(e){}
+    T* operator->() { return BiList<T>::ElemPtr::operator T*(); }
   };
   ElemPtr AddToBegin( T &t ) {
              return (ElemPtr)BiList<T>::AddToBegin(t);
