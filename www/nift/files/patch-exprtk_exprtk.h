--- exprtk/exprtk.h.orig	2024-01-13 12:54:06 UTC
+++ exprtk/exprtk.h
@@ -6340,7 +6340,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -6400,7 +6400,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -6463,7 +6463,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -6507,7 +6507,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -7782,7 +7782,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(index_, node_delete_list);
+            expression_node<T>::ndb_t::collect(index_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -11992,7 +11992,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -15283,7 +15283,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -15339,7 +15339,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -15406,7 +15406,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -15473,7 +15473,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
@@ -16040,7 +16040,7 @@ namespace exprtk
 
          void collect_nodes(typename expression_node<T>::noderef_list_t& node_delete_list)
          {
-            expression_node<T>::ndb_t::template collect(branch_, node_delete_list);
+            expression_node<T>::ndb_t::collect(branch_, node_delete_list);
          }
 
          std::size_t node_depth() const
