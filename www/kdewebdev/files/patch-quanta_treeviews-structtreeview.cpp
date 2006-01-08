--- quanta/treeviews/structtreeview.cpp.orig	Tue Dec 20 16:27:47 2005
+++ quanta/treeviews/structtreeview.cpp	Tue Dec 20 16:34:08 2005
@@ -776,7 +776,7 @@
         m_marker = current_item;
             
     if(current_item == m_draggedItem ||
-       !(e->provides("text/x-struct_tree_tag_item") || e->source() == this) || !m_marker)
+       !(e->provides("text/x-struct_tree_tag_item") || e->source() == (QWidget *)this) || !m_marker)
     {
         e->accept(false);
         last_accept = false;
