--- lib/list.h~	Sun Aug  1 15:46:43 2004
+++ lib/list.h	Sun Aug  1 16:26:21 2004
@@ -18,8 +18,8 @@
   typedef list_node<T> node;
   typedef list_iterator<T> iter;
   typedef const_list_iterator<T> const_iter;
-  friend class iter;
-  friend class const_iter;
+  friend class list_iterator<T>;
+  friend class const_list_iterator<T>;
   
   list()
     : head(0), tail(0), cnt(0)
@@ -111,8 +111,8 @@
     }
 private:
   const list<T>& lst;
-  const list<T>::node* prev;
-  const list<T>::node* curr;
+  const typename list<T>::node* prev;
+  const typename list<T>::node* curr;
 };
 
 template<class T>
@@ -164,8 +164,8 @@
     }
 private:
   list<T>& lst;
-  list<T>::node* prev;
-  list<T>::node* curr;
+  typename list<T>::node* prev;
+  typename list<T>::node* curr;
 };
 
 template<class T>
