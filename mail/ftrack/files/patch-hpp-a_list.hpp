--- hpp/a_list.hpp.orig	Tue Oct 28 04:01:58 2003
+++ hpp/a_list.hpp	Tue Oct 28 04:02:41 2003
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
@@ -294,7 +294,7 @@
   public:
   class ElemPtr : public BiList<T>::ElemPtr {
     public:
-    ElemPtr(BiList<T>::ElemPtr &e) : BiList<T>::ElemPtr(e){}
+    ElemPtr(typename BiList<T>::ElemPtr &e) : BiList<T>::ElemPtr(e){}
     T* operator->() { return operator T*(); }
   };
   ElemPtr AddToBegin( T &t ) {
