--- src/mn-gmail-mailbox-properties.c.orig	Tue Aug  9 22:01:56 2005
+++ src/mn-gmail-mailbox-properties.c	Wed Aug 10 14:29:05 2005
@@ -180,7 +180,7 @@
 				      GTK_ENTRY(auth->password_entry),
 				      NULL);
 
-    g_signal_connect(auth->username_entry, "changed", G_CALLBACK(mn_mailbox_properties_notify_default_name), self);
+    g_signal_connect_swapped(auth->username_entry, "changed", G_CALLBACK(mn_mailbox_properties_notify_default_name), self);
   
 #line 186 "mn-gmail-mailbox-properties.c"
  }
