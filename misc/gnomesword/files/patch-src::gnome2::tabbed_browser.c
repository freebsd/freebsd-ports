--- src/gnome2/tabbed_browser.c.orig	Thu Jun 17 04:53:24 2004
+++ src/gnome2/tabbed_browser.c	Sat Aug 21 15:59:13 2004
@@ -664,11 +664,13 @@
  */
 void gui_close_passage_tab(gint pagenum)
 {
+	PASSAGE_TAB_INFO *pt;
+
 	if (-1 == pagenum)
 		pagenum = gtk_notebook_get_current_page(GTK_NOTEBOOK(widgets.notebook_main));
 	if (1 == gtk_notebook_get_n_pages(GTK_NOTEBOOK(widgets.notebook_main)))
 		return;
-	PASSAGE_TAB_INFO *pt = (PASSAGE_TAB_INFO*)g_list_nth_data(passage_list, (guint)pagenum);
+	pt = (PASSAGE_TAB_INFO*)g_list_nth_data(passage_list, (guint)pagenum);
 	passage_list = g_list_remove(passage_list, pt);
 	if(pt->text_mod) g_free(pt->text_mod);
 	if(pt->commentary_mod) g_free(pt->commentary_mod);
