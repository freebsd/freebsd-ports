--- gtk/gtkmm/treeviewcolumn.h.orig	Mon Jul 21 14:45:01 2003
+++ gtk/gtkmm/treeviewcolumn.h	Mon Jul 21 14:45:28 2003
@@ -577,7 +577,7 @@
 void TreeViewColumn::pack_start(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
 {
   //Generate appropriate Renderer for the column:
-  CellRenderer* pCellRenderer = manage( TreeViewColumn_CellRendererGeneration::generate_cellrenderer<T_ModelColumnType>() );
+  CellRenderer* pCellRenderer = manage( TreeViewColumn_CellRendererGeneration::generate_cellrenderer<T_ModelColumnType>(false) );
 
   //Use the renderer:
   pack_start(*pCellRenderer, expand);
@@ -588,7 +588,7 @@
 void TreeViewColumn::pack_end(const TreeModelColumn<T_ModelColumnType>& column, bool expand)
 {
   //Generate appropriate Renderer for the column:
-  CellRenderer* pCellRenderer= manage( TreeViewColumn_CellRendererGeneration::generate_cellrenderer<T_ModelColumnType>() );
+  CellRenderer* pCellRenderer= manage( TreeViewColumn_CellRendererGeneration::generate_cellrenderer<T_ModelColumnType>(false) );
 
   //Use the renderer:
   pack_end(*pCellRenderer, expand);
