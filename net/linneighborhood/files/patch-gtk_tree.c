--- src/gtk_tree.c.orig	Wed Apr  9 20:32:53 2003
+++ src/gtk_tree.c	Wed Apr  9 20:48:24 2003
@@ -2011,7 +2011,7 @@
     if ( GTK_IS_TREE_ITEM(item) )
     {
       box = GTK_BIN(item)->child;
-
+      if (!box) return itemtype;
       step_list = GTK_BOX(box)->children->next;  /* type entry */
       child = step_list->data;
       label = GTK_LABEL(child->widget);
@@ -2033,7 +2033,6 @@
 static unsigned int tree_item_count (GtkTreeItem *item)
 {
   unsigned int ireturn;
-
   if ( item != NULL )
   {
     if ( item->subtree )
