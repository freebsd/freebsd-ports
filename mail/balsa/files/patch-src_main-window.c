--- src/main-window.c.orig	2011-08-16 13:32:27.000000000 +0200
+++ src/main-window.c	2011-08-16 13:33:10.000000000 +0200
@@ -3406,7 +3406,7 @@ bw_display_new_mail_notification(int num
         } else {
             num_total = num_new;
             balsa_app.main_window->new_mail_note =
-                notify_notification_new("Balsa", NULL, NULL, NULL);
+                notify_notification_new("Balsa", NULL, NULL);
             g_object_add_weak_pointer(G_OBJECT(balsa_app.main_window->
                                                new_mail_note),
                                       (gpointer) & balsa_app.main_window->
