--- lib/Video/DVDRip/GUI/Project/BurnTab.pm.orig	Sun Feb 22 12:33:01 2004
+++ lib/Video/DVDRip/GUI/Project/BurnTab.pm	Sun Feb 22 12:33:22 2004
@@ -550,18 +550,6 @@
 	$button_box->show;
 	$frame_vbox->pack_start ($button_box, 0, 1, 0);
 
-	# Eject Button
-	$button = Gtk::Button->new_with_label (" Open burner tray ");
-	$button->show;
-	$button->signal_connect ("clicked", sub { $self->eject_media } );
-	$button_box->pack_start ($button, 0, 1, 0);
-
-	# Insert Button
-	$button = Gtk::Button->new_with_label (" Close burner tray ");
-	$button->show;
-	$button->signal_connect ("clicked", sub { $self->insert_media } );
-	$button_box->pack_start ($button, 0, 1, 0);
-
 	# Blank CD-RW button
 	$button = Gtk::Button->new_with_label (" Blank CD-RW ");
 	$button->show;
