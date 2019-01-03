The io.elementary.desktop.wingpanel.datetime schema is not available,
which leads to crashes when using the DateTime widget.  Use the
org.gnome.desktop.interface schema instead as documented in the API
docs.

cf. https://github.com/elementary/granite/pull/222

--- lib/DateTime.vala.orig	2018-12-17 13:02:11 UTC
+++ lib/DateTime.vala
@@ -110,7 +110,7 @@ namespace Granite.DateTime {
      * @return true if the clock format is 12h based, false otherwise.
      */
     private static bool is_clock_format_12h () {
-        var h24_settings = new Settings ("io.elementary.desktop.wingpanel.datetime");
+        var h24_settings = new Settings ("org.gnome.desktop.interface");
         var format = h24_settings.get_string ("clock-format");
         return (format.contains ("12h"));
     }
