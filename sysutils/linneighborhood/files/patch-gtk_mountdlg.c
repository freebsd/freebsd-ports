--- src/gtk_mountdlg.c.orig	Wed Apr  9 19:51:41 2003
+++ src/gtk_mountdlg.c	Wed Apr  9 20:18:14 2003
@@ -726,65 +726,65 @@
     
    /*root password */
    frame = gtk_frame_new(_("Mount as Root"));
-   gtk_box_pack_start(GTK_BOX (GTK_DIALOG (mount_dlg)->vbox), frame, TRUE, TRUE, 5);
-   gtk_widget_show(frame);   
+//   gtk_box_pack_start(GTK_BOX (GTK_DIALOG (mount_dlg)->vbox), frame, TRUE, TRUE, 5);
+//   gtk_widget_show(frame);   
    
    vbox=gtk_vbox_new(FALSE,0);
-   gtk_container_border_width(GTK_CONTAINER(vbox), 3);
-   gtk_container_add(GTK_CONTAINER(frame),vbox);
-   gtk_widget_show(vbox);
+//   gtk_container_border_width(GTK_CONTAINER(vbox), 3);
+//   gtk_container_add(GTK_CONTAINER(frame),vbox);
+//   gtk_widget_show(vbox);
 
    hbox=gtk_hbox_new(FALSE,0);
 /*   gtk_box_pack_start(GTK_BOX (GTK_DIALOG (mount_dlg)->vbox),
                     	hbox, TRUE, TRUE, 5);
    gtk_container_border_width(GTK_CONTAINER(hbox), 3);
    gtk_container_add(GTK_CONTAINER(frame),hbox); */
-   gtk_box_pack_start(GTK_BOX (vbox),hbox, TRUE, TRUE, 0);
-   gtk_widget_show(hbox);
+//   gtk_box_pack_start(GTK_BOX (vbox),hbox, TRUE, TRUE, 0);
+//   gtk_widget_show(hbox);
 
    sumountcheckbox = gtk_check_button_new_with_label(_("OK"));
 /*   gtk_widget_set_usize(sumountcheckbox,120,-1); */
-   if (geteuid()==0) /*No root password if you are root*/
-     gtk_widget_set_sensitive(sumountcheckbox,FALSE);
-   gtk_toggle_button_set_state(GTK_TOGGLE_BUTTON(sumountcheckbox),cachesupwd & sumount);
-   gtk_box_pack_start (GTK_BOX (hbox), sumountcheckbox, FALSE, TRUE, 0);
-   gtk_widget_show (sumountcheckbox);
+//   if (geteuid()==0) /*No root password if you are root*/
+//     gtk_widget_set_sensitive(sumountcheckbox,FALSE);
+//   gtk_toggle_button_set_state(GTK_TOGGLE_BUTTON(sumountcheckbox),cachesupwd & sumount);
+//   gtk_box_pack_start (GTK_BOX (hbox), sumountcheckbox, FALSE, TRUE, 0);
+//   gtk_widget_show (sumountcheckbox);
 
    label=gtk_label_new(_("Password:"));
-   gtk_box_pack_start(GTK_BOX (hbox),label, FALSE, TRUE, 0);
+//   gtk_box_pack_start(GTK_BOX (hbox),label, FALSE, TRUE, 0);
 /*   gtk_widget_set_usize(label,100,-1); */
-   gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_LEFT);
-   gtk_widget_show(label);
+//   gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_LEFT);
+//   gtk_widget_show(label);
 
    supasswdentry= gtk_entry_new_with_max_length(MASTER_LEN);
-   gtk_entry_set_visibility(GTK_ENTRY(supasswdentry), 0);
+//   gtk_entry_set_visibility(GTK_ENTRY(supasswdentry), 0);
 
-   if (sumount && cachesupwd)
-     gtk_entry_set_text (GTK_ENTRY (supasswdentry), supasswd);
-   else
-     gtk_entry_set_text (GTK_ENTRY (supasswdentry), "");
+//   if (sumount && cachesupwd)
+//     gtk_entry_set_text (GTK_ENTRY (supasswdentry), supasswd);
+//   else
+//     gtk_entry_set_text (GTK_ENTRY (supasswdentry), "");
   
-   gtk_widget_set_sensitive(supasswdentry,sumount&cachesupwd);
-   gtk_signal_connect_object(GTK_OBJECT(supasswdentry), "key_press_event",
-                  	GTK_SIGNAL_FUNC(smb_mount_key_press_callback), NULL);
-   gtk_box_pack_start (GTK_BOX (hbox), supasswdentry, TRUE, TRUE, 5);
-   gtk_widget_show (supasswdentry);
-   gtk_signal_connect (GTK_OBJECT(sumountcheckbox), "toggled",
-                GTK_SIGNAL_FUNC(supwentry_toggle_sensitive),supasswdentry);
+//   gtk_widget_set_sensitive(supasswdentry,sumount&cachesupwd);
+//   gtk_signal_connect_object(GTK_OBJECT(supasswdentry), "key_press_event",
+//                  	GTK_SIGNAL_FUNC(smb_mount_key_press_callback), NULL);
+//   gtk_box_pack_start (GTK_BOX (hbox), supasswdentry, TRUE, TRUE, 5);
+//   gtk_widget_show (supasswdentry);
+//   gtk_signal_connect (GTK_OBJECT(sumountcheckbox), "toggled",
+//                GTK_SIGNAL_FUNC(supwentry_toggle_sensitive),supasswdentry);
 
    hbox=gtk_hbox_new(FALSE,0);
-   gtk_box_pack_start(GTK_BOX (vbox),hbox, TRUE, TRUE, 0);
-   gtk_widget_show(hbox);
+//   gtk_box_pack_start(GTK_BOX (vbox),hbox, TRUE, TRUE, 0);
+//   gtk_widget_show(hbox);
 
    sucachepwdcheckbox = gtk_check_button_new_with_label(_("Cache Root Password"));
 
 /*   gtk_widget_set_usize(sumountcheckbox,120,-1); */
-   if (geteuid()==0) 
-     gtk_widget_set_sensitive(sumountcheckbox,FALSE);
-   gtk_toggle_button_set_state(GTK_TOGGLE_BUTTON(sucachepwdcheckbox),cachesupwd &sumount);
-   gtk_widget_set_sensitive(sucachepwdcheckbox,sumount);
-   gtk_box_pack_start (GTK_BOX (hbox), sucachepwdcheckbox, FALSE, TRUE, 0);
-   gtk_widget_show (sucachepwdcheckbox);
+//   if (geteuid()==0) 
+//     gtk_widget_set_sensitive(sumountcheckbox,FALSE);
+//   gtk_toggle_button_set_state(GTK_TOGGLE_BUTTON(sucachepwdcheckbox),cachesupwd &sumount);
+//   gtk_widget_set_sensitive(sucachepwdcheckbox,sumount);
+//   gtk_box_pack_start (GTK_BOX (hbox), sucachepwdcheckbox, FALSE, TRUE, 0);
+//   gtk_widget_show (sucachepwdcheckbox);
 
    /*-action_area*/
    mount_button = gtk_button_new_with_label(_("Mount"));
