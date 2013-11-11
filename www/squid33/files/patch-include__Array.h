--- include/Array.h.orig	2013-05-20 13:48:55.000000000 +0200
+++ include/Array.h	2013-07-15 23:00:06.000000000 +0200
@@ -42,12 +42,19 @@
 #include "compat/assert.h"
 
 /* iterator support */
+#include <iterator>
 
 template <class C>
 class VectorIteratorBase
 {
 
 public:
+    typedef typename C::value_type value_type;
+    typedef std::forward_iterator_tag iterator_category;
+    typedef typename C::pointer pointer;
+    typedef typename C::reference reference;
+    typedef typename C::difference_type difference_type;
+
     VectorIteratorBase();
     VectorIteratorBase(C &);
     VectorIteratorBase(size_t, C &);
@@ -79,8 +86,10 @@
 public:
     typedef E value_type;
     typedef E* pointer;
+    typedef E& reference;
     typedef VectorIteratorBase<Vector<E> > iterator;
     typedef VectorIteratorBase<Vector<E> const> const_iterator;
+    typedef ptrdiff_t difference_type;
 
     void *operator new (size_t);
     void operator delete (void *);
