--- src/bftextview2_autocomp.c.orig	2023-07-04 14:09:37 UTC
+++ src/bftextview2_autocomp.c
@@ -429,7 +429,7 @@ acwin_create(BluefishTextView * btv)
 	/*gtk_widget_set_size_request(acw->reflabel,150,-1); */
 	gtk_widget_show_all(acw->scroll);
 	gtk_widget_show(hbox);
-	g_signal_connect(acw->reflabel, "activate-link", acw_label_active_link_lcb, acw);
+	g_signal_connect(acw->reflabel, "activate-link", G_CALLBACK(acw_label_active_link_lcb), acw);
 	/*gtk_widget_set_size_request(GTK_WIDGET(acw->tree),100,200); */
 	/*gtk_widget_set_size_request(acw->win, 150, 200); */
 	/*g_signal_connect(G_OBJECT(acw->win),"key-release-event",G_CALLBACK(acwin_key_release_lcb),acw); */
