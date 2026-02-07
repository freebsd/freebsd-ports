--- include/CGAL/AABB_tree.h.orig	2024-12-26 01:08:55 UTC
+++ include/CGAL/AABB_tree.h
@@ -553,7 +553,7 @@ namespace CGAL { (public)
         traits.intersection(query, singleton_data());
         break;
       default: // if(size() >= 2)
-        root_node()->template traversal_with_priority_and_group_traversal(m_primitives, query, traits, m_primitives.size(), 0, group_traversal_bound);
+        root_node()->traversal_with_priority_and_group_traversal(m_primitives, query, traits, m_primitives.size(), 0, group_traversal_bound);
       }
     }
 
