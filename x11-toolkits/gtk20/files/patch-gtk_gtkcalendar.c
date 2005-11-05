--- gtk/gtkcalendar.c.orig	Mon Oct  3 22:01:14 2005
+++ gtk/gtkcalendar.c	Mon Oct  3 22:02:36 2005
@@ -566,6 +566,7 @@ gtk_calendar_init (GtkCalendar *calendar
   GtkCalendarPrivate *priv;
   gchar *year_before;
   gchar *langinfo;
+  gchar *week_start;
   gint week_1stday = 0;
   gint first_weekday = 1;
   guint week_origin;
