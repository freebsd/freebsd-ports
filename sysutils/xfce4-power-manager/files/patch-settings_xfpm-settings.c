--- settings/xfpm-settings.c.orig	2017-11-23 23:52:06 UTC
+++ settings/xfpm-settings.c
@@ -1499,9 +1499,9 @@ format_light_locker_value_cb (GtkScale *scale, gdouble
 
     if ( (gint)value <= 0 )
         return g_strdup (_("Never"));
-    else if ( value <= 59.0 )
+    else if ( value < 60.0 )
         return g_strdup_printf ("%d %s", (gint)value, _("seconds"));
-    else if ( value >= 60.0)
+    else
     {
         min = (gint)value - 60;
         if (min == 0)
