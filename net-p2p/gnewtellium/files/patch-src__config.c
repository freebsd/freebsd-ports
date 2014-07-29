--- src/config.c.orig	Tue Feb  5 03:50:18 2002
+++ src/config.c	Tue Mar  9 20:37:00 2004
@@ -539,8 +539,8 @@
 	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
 	gtk_widget_show(hbox);
 
-	label = gtk_label_new("Let Newtella know what speed your Internet Connection is.
-Setting this to an accurate number will help you get the most out of
+	label = gtk_label_new("Let Newtella know what speed your Internet Connection is.\n\
+Setting this to an accurate number will help you get the most out of\n\
 Newtella's advanced bandwidth management.");
 	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
 	hbox = gtk_hbox_new(FALSE, 0);
@@ -579,7 +579,7 @@
 	gtk_widget_show(button);
 
 	hbox = gtk_hbox_new(FALSE, 0);
-	label = gtk_label_new("Select the directory where you want to store your newly
+	label = gtk_label_new("Select the directory where you want to store your newly\n\
 downloaded files.");
 	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 10);
@@ -627,8 +627,8 @@
 	gtk_widget_show(hbox);
 	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
 
-	label = gtk_label_new("Add any number of directories here.
-All .mp3 files under any of these directories can then be
+	label = gtk_label_new("Add any number of directories here.\n\
+All .mp3 files under any of these directories can then be\n\
 downloaded by other Newtella users.");
 	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
 	hbox = gtk_hbox_new(FALSE, 0);
@@ -686,8 +686,8 @@
 	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 10);
 
 	hbox = gtk_hbox_new(FALSE, 0);
-	label = gtk_label_new("Select how much search results Newtella will maximally send to
-other clients. Use this to limit the impact of stupid searches on your
+	label = gtk_label_new("Select how much search results Newtella will maximally send to\n\
+other clients. Use this to limit the impact of stupid searches on your\n\
 computer.");
 	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 10);
@@ -724,8 +724,8 @@
 	gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 10);
 
 	hbox = gtk_hbox_new(FALSE, 0);
-	label = gtk_label_new("Returns the entered IP with search results instead of your real one.
-Useful if your're behind a NAT Firewall (like Windows 98 Internet
+	label = gtk_label_new("Returns the entered IP with search results instead of your real one.\n\
+Useful if your're behind a NAT Firewall (like Windows 98 Internet\n\
 Connection Sharing)");
 	gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
 	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 10);
