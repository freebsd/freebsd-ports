--- email/email_conduit.c.orig	Tue Apr 15 02:29:36 2003
+++ email/email_conduit.c	Tue Apr 15 02:30:00 2003
@@ -47,7 +47,7 @@
 	prefix = g_strdup_printf("/gnome-pilot.d/email-conduit/Pilot_%u/",pilotId);
   
 	gnome_config_push_prefix(prefix);
-	(*c)->sendmail = gnome_config_get_string( "sendmail=/usr/lib/sendmail -t -i");
+	(*c)->sendmail = gnome_config_get_string( "sendmail=/usr/sbin/sendmail -t -i");
 	(*c)->fromAddr = gnome_config_get_string( "from_address" );
 	(*c)->sendAction = gnome_config_get_string( "send_action=file");
 	(*c)->mhDirectory = gnome_config_get_string( "mh_directory" );
