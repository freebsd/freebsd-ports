From 6ace67d382e7a138e86a5677dc4a999853d3ecdc Mon Sep 17 00:00:00 2001
From: monsta <monsta@inbox.ru>
Date: Thu, 31 Aug 2017 16:28:21 +0300
Subject: [PATCH] Revert "Adds columns autosizing"

This reverts commit ee0de1a5e74cbed5cf49517ea82a73e52dd6424a.
--- src/file-manager/fm-list-view.c.orig	2017-08-26 09:34:58 UTC
+++ src/file-manager/fm-list-view.c
@@ -1765,7 +1765,6 @@ create_and_set_up_tree_view (FMListView *view)
             gtk_tree_view_column_set_sort_column_id (view->details->file_name_column, column_num);
             gtk_tree_view_column_set_title (view->details->file_name_column, _("Name"));
             gtk_tree_view_column_set_resizable (view->details->file_name_column, TRUE);
-            gtk_tree_view_column_set_sizing(view->details->file_name_column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
 
             gtk_tree_view_column_pack_start (view->details->file_name_column, cell, FALSE);
             gtk_tree_view_column_set_attributes (view->details->file_name_column,
@@ -1805,7 +1804,6 @@ create_and_set_up_tree_view (FMListView *view)
                                  column);
 
             gtk_tree_view_column_set_resizable (column, TRUE);
-            gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
         }
         g_free (name);
         g_free (label);
