--- lib/list.h~	Sat Mar  5 01:16:28 2005
+++ lib/list.h	Sat Mar  5 01:13:35 2005
@@ -18,8 +18,8 @@
   typedef list_node<T> node;
   typedef list_iterator<T> iter;
   typedef const_list_iterator<T> const_iter;
-  friend class iter;
-  friend class const_iter;
+  friend class list_iterator<T>;;
+  friend class const_list_iterator<T>;;
   
   list()
     : head(0), tail(0), cnt(0)
