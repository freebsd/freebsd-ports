--- ./libs/libmyth/mythdeque.h	(revision 20349)
+++ ./libs/libmyth/mythdeque.h	(revision 26434)
@@ -4,6 +4,12 @@
 #define __MYTH_DEQUE_H__
 
+#include <QString>
 #include <deque>
 using namespace std;
+
+template<typename T>
+inline T myth_deque_init(const T*) { return (T)(0); }
+template<>
+inline QString myth_deque_init(const QString*) { return QString(); }
 
 /** \class MythDeque
@@ -19,6 +25,7 @@
     T dequeue()
     {
+        T *dummy = NULL;
         if (deque<T>::empty())
-            return (T)(0);
+            return myth_deque_init(dummy);
         T item = deque<T>::front();
         deque<T>::pop_front();
@@ -66,14 +73,20 @@
 
     /// \brief Returns item at head of list. O(1).
-    T head() { return (deque<T>::size()) ? deque<T>::front() : (T)(NULL); }
+    T head()
+        { if (!deque<T>::empty()) return deque<T>::front();
+          T *dummy = NULL; return myth_deque_init(dummy); }
     /// \brief Returns item at head of list. O(1).
     const T head() const
-        { return (deque<T>::size()) ? deque<T>::front() : (T)(NULL); }
+        { if (!deque<T>::empty()) return deque<T>::front();
+          T *dummy = NULL; return myth_deque_init(dummy); }
 
     /// \brief Returns item at tail of list. O(1).
-    T tail() { return (deque<T>::size()) ? deque<T>::back() : (T)(NULL); }
+    T tail()
+        { if (!deque<T>::empty()) return deque<T>::back();
+          T *dummy = NULL; return myth_deque_init(dummy); }
     /// \brief Returns item at tail of list. O(1).
     const T tail() const
-        { return (deque<T>::size()) ? deque<T>::back() : (T)(NULL); }
+        { if (!deque<T>::empty()) return deque<T>::back();
+          T *dummy = NULL; return myth_deque_init(dummy); }
 };
 
