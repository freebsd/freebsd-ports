*** hozgtk_i.c	Tue Feb 17 09:31:38 2004
--- /home/acardenas/hoz-165/hozgtk_i.c	Fri Sep 16 17:53:15 2005
***************
*** 119,129 ****
    gtk_combo_set_popdown_strings (GTK_COMBO (combo_size), combo_size_items);
    g_list_free (combo_size_items);
  
    combo_entry_size = GTK_COMBO (combo_size)->entry;
    gtk_widget_show (combo_entry_size);
!   gtk_widget_set_size_request (combo_entry_size, 50, -2);
    gtk_editable_set_editable (GTK_EDITABLE (combo_entry_size), FALSE);
    gtk_entry_set_text (GTK_ENTRY (combo_entry_size), "bytes");
  
    g_signal_connect ((gpointer) window_hoz, "destroy",
                      G_CALLBACK (on_window_hoz_destroy),
--- 119,129 ----
    gtk_combo_set_popdown_strings (GTK_COMBO (combo_size), combo_size_items);
    g_list_free (combo_size_items);
  
    combo_entry_size = GTK_COMBO (combo_size)->entry;
    gtk_widget_show (combo_entry_size);
!   gtk_widget_set_size_request (combo_entry_size, 50, -1);
    gtk_editable_set_editable (GTK_EDITABLE (combo_entry_size), FALSE);
    gtk_entry_set_text (GTK_ENTRY (combo_entry_size), "bytes");
  
    g_signal_connect ((gpointer) window_hoz, "destroy",
                      G_CALLBACK (on_window_hoz_destroy),
