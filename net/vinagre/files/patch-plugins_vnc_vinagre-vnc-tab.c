Increase the accepted length of passwords.

- VNC only accepts 8 characters; however some impelementations allow for longer
  passwords to be used. Increase the passwords that can be entered to 32 chars.

https://bugzilla.gnome.org/show_bug.cgi?id=652334
https://gitlab.gnome.org/GNOME/vinagre/-/issues/17
https://bugzilla.redhat.com/show_bug.cgi?id=1767963

--- plugins/vnc/vinagre-vnc-tab.c.orig
+++ plugins/vnc/vinagre-vnc-tab.c
@@ -508,7 +508,7 @@
 	{
 	  host = vinagre_connection_get_best_name (conn);
 	  if (!vinagre_utils_request_credential (window, "VNC", host, NULL, NULL,
-	     FALSE, need_username, need_password, 8, NULL, &username, &password,
+	     FALSE, need_username, need_password, 32, NULL, &username, &password,
 	     &save_in_keyring))
 	    {
 	      vinagre_tab_remove_from_notebook (tab);
