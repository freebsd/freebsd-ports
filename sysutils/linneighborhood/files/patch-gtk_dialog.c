--- src/gtk_dialog.c.orig	Sun Apr  6 13:07:13 2003
+++ src/gtk_dialog.c	Sun Apr  6 13:10:50 2003
@@ -2039,34 +2039,34 @@
     gtk_widget_show(button);
     
     frame = gtk_frame_new(_(" smbmount version "));
-    gtk_container_border_width(GTK_CONTAINER(frame), 3);
-    gtk_box_pack_start(GTK_BOX(frame_vbox), frame, FALSE, TRUE, 0);
-    gtk_widget_show(frame);
+//    gtk_container_border_width(GTK_CONTAINER(frame), 3);
+//    gtk_box_pack_start(GTK_BOX(frame_vbox), frame, FALSE, TRUE, 0);
+//    gtk_widget_show(frame);
     
     frame_vbox = gtk_vbox_new(FALSE, 0);
-    gtk_container_border_width(GTK_CONTAINER(frame_vbox), 5);
-    gtk_container_add(GTK_CONTAINER(frame), frame_vbox);
-    gtk_widget_show(frame_vbox);
+//    gtk_container_border_width(GTK_CONTAINER(frame_vbox), 5);
+//    gtk_container_add(GTK_CONTAINER(frame), frame_vbox);
+//    gtk_widget_show(frame_vbox);
 
     smbmount_204_radio = gtk_radio_button_new_with_label(NULL, _("version <= 2.0.4"));
-    if ( globals.linux_version < LINUX_2_2 )
-      gtk_widget_set_sensitive(smbmount_204_radio, FALSE);
-    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_204_radio, FALSE, TRUE, 0);
-    gtk_widget_show(smbmount_204_radio);
+//    if ( globals.linux_version < LINUX_2_2 )
+//      gtk_widget_set_sensitive(smbmount_204_radio, FALSE);
+//    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_204_radio, FALSE, TRUE, 0);
+//    gtk_widget_show(smbmount_204_radio);
 
     smbmount_205_radio = gtk_radio_button_new_with_label(
         gtk_radio_button_group(GTK_RADIO_BUTTON(smbmount_204_radio)), _("version = 2.0.5"));
-    if ( globals.linux_version < LINUX_2_2 )
-      gtk_widget_set_sensitive(smbmount_205_radio, FALSE);
-    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_205_radio, FALSE, TRUE, 0);
-    gtk_widget_show(smbmount_205_radio);
+//    if ( globals.linux_version < LINUX_2_2 )
+//      gtk_widget_set_sensitive(smbmount_205_radio, FALSE);
+//    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_205_radio, FALSE, TRUE, 0);
+//    gtk_widget_show(smbmount_205_radio);
 
     smbmount_206_radio = gtk_radio_button_new_with_label(
         gtk_radio_button_group(GTK_RADIO_BUTTON(smbmount_205_radio)), _("version >= 2.0.6"));
-    if ( globals.linux_version < LINUX_2_2 )
-      gtk_widget_set_sensitive(smbmount_206_radio, FALSE);
-    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_206_radio, FALSE, TRUE, 0);
-    gtk_widget_show(smbmount_206_radio);
+//    if ( globals.linux_version < LINUX_2_2 )
+//      gtk_widget_set_sensitive(smbmount_206_radio, FALSE);
+//    gtk_box_pack_start(GTK_BOX(frame_vbox), smbmount_206_radio, FALSE, TRUE, 0);
+//    gtk_widget_show(smbmount_206_radio);
     
     switch ( pref.v.smbmount_version )
     {
