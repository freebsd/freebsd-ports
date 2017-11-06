--- extensions/transfers.vala.orig	2015-08-30 11:56:26 UTC
+++ extensions/transfers.vala
@@ -275,7 +275,11 @@ namespace Transfers {
                     Transfer found;
                     store.get (iter, 0, out found);
                     if (transfer == found) {
+#if VALA_0_36
+                        store.remove (ref iter);
+#else
                         store.remove (iter);
+#endif
                         break;
                     }
                 } while (store.iter_next (ref iter));
@@ -455,7 +459,11 @@ namespace Transfers {
                 if (notifications.length () == 1)
                     msg = _("The file '<b>%s</b>' has been downloaded.").printf (filename);
                 else
-                    msg = _("'<b>%s</b>' and %d other files have been downloaded.").printf (filename, notifications.length ());
+#if VALA_0_36
+                    msg = _("'<b>%s</b>' and %d other files have been downloaded.").printf (filename, (int) notifications.length ());
+#else
+                    msg = _("'<b>%s</b>' and %d other files have been downloaded.").printf (filename, notifications.length ());
+#endif
                 get_app ().send_notification (_("Transfer completed"), msg);
                 notifications = new GLib.List<string> ();
             }
