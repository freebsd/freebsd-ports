--- lib/Video/DVDRip/GUI/Project/BurnTab.pm.orig	Fri Jun 20 03:14:33 2003
+++ lib/Video/DVDRip/GUI/Project/BurnTab.pm	Fri Jun 20 03:15:21 2003
@@ -545,18 +545,6 @@
 
 	$widgets->{image_button} = $button;
 
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
 	return $frame;
 }
 
