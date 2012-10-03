--- ./midori/midori-download.vala.orig	2012-09-19 21:17:43.000000000 +0000
+++ ./midori/midori-download.vala	2012-09-21 14:29:25.000000000 +0000
@@ -46,8 +46,8 @@
             string filename = Path.get_basename (download.destination_uri);
             /* i18n: Download tooltip (size): 4KB of 43MB */
             string size = _("%s of %s").printf (
-                format_size (download.current_size),
-                format_size (download.total_size));
+                format_size_for_display ((int64) download.current_size),
+                format_size_for_display ((int64) download.total_size));
 
             /* Finished, no speed or remaining time */
             if (is_finished (download) || download.status == WebKit.DownloadStatus.CREATED)
@@ -84,7 +84,7 @@
 
             string speed;
             if (elapsed != last_time) {
-                speed = format_size ((uint64)(
+                speed = format_size_for_display ((int64)(
                     (current_size - last_size) / (elapsed - last_time)));
             }
             else
@@ -172,6 +172,8 @@
                     return Gtk.Stock.OPEN;
                 case WebKit.DownloadStatus.CANCELLED:
                     return Gtk.Stock.CLEAR;
+                case WebKit.DownloadStatus.ERROR:
+                    return Gtk.Stock.DIALOG_ERROR;
                 default:
                     critical ("action_stock_id: %d", download.status);
                     warn_if_reached ();
@@ -307,7 +309,7 @@
                     message = _("There is not enough free space to download \"%s\".").printf (
                         Path.get_basename (uri));
                     detailed_message = _("The file needs %s but only %s are left.").printf (
-                        format_size (download.total_size), format_size (free_space));
+                        format_size_for_display ((int64) download.total_size), format_size_for_display ((int64) free_space));
                 }
                 else
                     assert_not_reached ();
