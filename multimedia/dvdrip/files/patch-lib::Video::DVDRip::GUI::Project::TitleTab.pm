--- lib/Video/DVDRip/GUI/Project/TitleTab.pm.orig	Fri Jun 20 03:15:39 2003
+++ lib/Video/DVDRip/GUI/Project/TitleTab.pm	Fri Jun 20 03:16:55 2003
@@ -60,30 +60,6 @@
 	$hbox->pack_start ( $button, 0, 1, 0);
 #	$hbox->pack_start ( $label, 0, 1, 0);
 
-        # Eject Button
-        $button = Gtk::Button->new_with_label (
-                " Open DVD tray"
-        );
-        $button->show;
-        $button->signal_connect ("clicked",
-                sub { $self->eject_dvd }
-        );
-        $hbox->pack_start ($button, 0, 1, 0);
-
-        $self->rip_title_widgets->{eject_dvd_button} = $button;
-
-        # Insert Button
-        $button = Gtk::Button->new_with_label (
-                " Close DVD tray "
-        );
-        $button->show;
-        $button->signal_connect ("clicked",
-                sub { $self->insert_dvd }
-        );
-        $hbox->pack_start ($button, 0, 1, 0);
-
-        $self->rip_title_widgets->{insert_dvd_button} = $button;
-
 	$frame->add ($hbox);
 	$vbox->pack_start ( $frame, 0, 1, 0);
 
