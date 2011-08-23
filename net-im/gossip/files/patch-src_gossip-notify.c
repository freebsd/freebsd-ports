--- src/gossip-notify.c.orig	2011-08-15 19:59:28.000000000 +0200
+++ src/gossip-notify.c	2011-08-15 20:03:01.000000000 +0200
@@ -225,7 +225,7 @@ notify_contact_online (GossipContact *co
 					gossip_contact_get_name (contact),
 					notify_get_default_status_from_presence (presence));
 
-	notify = notify_notification_new (_("Contact Online"), body, NULL, NULL);
+	notify = notify_notification_new (_("Contact Online"), body, NULL);
 	notify_notification_set_urgency (notify, NOTIFY_URGENCY_LOW);
 	notify_notification_set_icon_from_pixbuf (notify, pixbuf);
 
@@ -234,10 +234,6 @@ notify_contact_online (GossipContact *co
 			  G_CALLBACK (notify_closed_cb),
 			  NULL);
 
-	if (attach_status_icon) {
-		notify_notification_attach_to_status_icon (notify, attach_status_icon);
-	}
-
 	notify_notification_add_action (notify, "default", _("Default"),
 					(NotifyActionCallback) notify_online_action_cb,
 					g_object_ref (contact), NULL);
@@ -330,14 +326,9 @@ notify_subscription_request_show (Gossip
 
 	notify = notify_notification_new (_("Subscription Request"),
 					  message,
-					  NULL,
 					  NULL);
 	g_free (message);
 
-	if (attach_status_icon) {
-		notify_notification_attach_to_status_icon (notify, attach_status_icon);
-	}
-
 	notify_notification_set_urgency (notify, NOTIFY_URGENCY_NORMAL);
 	notify_notification_set_timeout (notify, NOTIFY_SUBSCRIPTION_TIME);
 
@@ -377,15 +368,10 @@ notify_file_transfer_request (GossipFT *
 						     gossip_ft_get_file_name (ft));
 	notification = notify_notification_new (_("File Transfer"),
 					  	notification_body,
-					  	NULL,
 					  	NULL);
 
 	g_free (notification_body);
 	
-	if (attach_status_icon) {
-		notify_notification_attach_to_status_icon (notification, attach_status_icon);
-	}
-
 	notify_notification_set_urgency (notification, NOTIFY_URGENCY_NORMAL);
 
 	error = NULL;
@@ -546,7 +532,7 @@ notify_new_message (GossipEventManager *
 		str = g_markup_printf_escaped (_("“%s”"), body_stripped);
 	}
 
-	notify = notify_notification_new (title, str, NULL, NULL);
+	notify = notify_notification_new (title, str, NULL);
 	notify_notification_set_urgency (notify, NOTIFY_URGENCY_NORMAL);
 	notify_notification_set_icon_from_pixbuf (notify, pixbuf);
 	notify_notification_set_timeout (notify, NOTIFY_MESSAGE_TIME);
@@ -556,10 +542,6 @@ notify_new_message (GossipEventManager *
 			  G_CALLBACK (notify_closed_cb),
 			  NULL);
 
-	if (attach_status_icon) {
-		notify_notification_attach_to_status_icon (notify, attach_status_icon);
-	}
-
 	notify_notification_add_action (notify, "default", _("Default"),
 					(NotifyActionCallback) notify_new_message_default_cb,
 					g_object_ref (event_manager), NULL);
@@ -901,7 +883,7 @@ gossip_notify_hint_show (const gchar    
 		return FALSE;
 	}
 
-	notify = notify_notification_new (summary, message, NULL, NULL);
+	notify = notify_notification_new (summary, message, NULL);
 	g_object_set_data_full (G_OBJECT (notify), "conf_path", g_strdup (conf_path), g_free);
 	g_object_set_data (G_OBJECT (notify), "func", func);
 	g_signal_connect (notify,
@@ -909,10 +891,6 @@ gossip_notify_hint_show (const gchar    
 			  G_CALLBACK (notify_hint_closed_cb),
 			  user_data);
 
-	if (attach_status_icon) {
-		notify_notification_attach_to_status_icon (notify, attach_status_icon);
-	}
-
 	if (!notify_notification_show (notify, &error)) {
 		g_warning ("Failed to send notification: %s",
 			   error->message);
