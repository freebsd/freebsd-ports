--- ./src/plugins/vcalendar/vcal_meeting_gtk.c.orig	2013-03-19 07:31:04.000000000 +0100
+++ ./src/plugins/vcalendar/vcal_meeting_gtk.c	2013-09-28 16:28:18.000000000 +0200
@@ -1433,15 +1433,31 @@
 
 	times = get_predefined_times();
 
-	meet->start_time 	= gtk_combo_box_entry_new_text ();
+#if !GTK_CHECK_VERSION(2, 24, 0)
+	meet->start_time = gtk_combo_box_entry_new_text();
+#else
+	meet->start_time = gtk_combo_box_text_new_with_entry();
+#endif
 	gtk_combo_box_set_active(GTK_COMBO_BOX(meet->start_time), -1);
 	menu = GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(meet->start_time)));
+#if !GTK_CHECK_VERSION(2, 24, 0)	
 	combobox_set_popdown_strings(GTK_COMBO_BOX(meet->start_time), times);
-
-	meet->end_time 		= gtk_combo_box_entry_new_text ();
+#else	
+	combobox_set_popdown_strings(GTK_COMBO_BOX_TEXT(meet->start_time), times);
+#endif
+	
+#if !GTK_CHECK_VERSION(2, 24, 0)
+	meet->end_time = gtk_combo_box_entry_new_text();
+#else
+	meet->end_time = gtk_combo_box_text_new_with_entry();
+#endif
 	gtk_combo_box_set_active(GTK_COMBO_BOX(meet->end_time), -1);
 	menu = GTK_LIST_STORE(gtk_combo_box_get_model(GTK_COMBO_BOX(meet->end_time)));
+#if !GTK_CHECK_VERSION(2, 24, 0)	
 	combobox_set_popdown_strings(GTK_COMBO_BOX(meet->end_time), times);
+#else	
+	combobox_set_popdown_strings(GTK_COMBO_BOX_TEXT(meet->end_time), times);
+#endif
 
 	list_free_strings(times);
 	g_list_free(times);
@@ -1597,12 +1613,14 @@
 	date_hbox = gtk_hbox_new(FALSE, 6);
 	date_vbox = gtk_vbox_new(FALSE, 6);
 	hbox = gtk_hbox_new(FALSE, 6);
-	label = gtk_label_new(_("<b>Starts at:</b> ")); gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
+	label = gtk_label_new(_("<b>Starts at:</b> "));
+	gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
 	gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
 	
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(hbox), meet->start_time, FALSE, FALSE, 0);
-	label = gtk_label_new(_("<b> on:</b>")); gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
+	label = gtk_label_new(_("<b> on:</b>"));
+	gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
 	gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(date_vbox), hbox, FALSE, FALSE, 0);
@@ -1619,12 +1637,14 @@
 
 	date_vbox = gtk_vbox_new(FALSE, 6);
 	hbox = gtk_hbox_new(FALSE, 6);
-	label = gtk_label_new(_("<b>Ends at:</b> ")); gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
+	label = gtk_label_new(_("<b>Ends at:</b> ")); 
+	gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
 	gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
 	
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(hbox), meet->end_time, FALSE, FALSE, 0);
-	label = gtk_label_new(_("<b> on:</b>")); gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
+	label = gtk_label_new(_("<b> on:</b>")); 
+	gtk_misc_set_alignment(GTK_MISC(label), 0, 0.5);
 	gtk_label_set_use_markup(GTK_LABEL(label), TRUE);
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
 	gtk_box_pack_start(GTK_BOX(date_vbox), hbox, FALSE, FALSE, 0);
