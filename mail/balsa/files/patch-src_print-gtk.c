--- src/print-gtk.c.orig	Thu May  3 22:59:46 2007
+++ src/print-gtk.c	Thu May  3 23:01:30 2007
@@ -378,12 +378,14 @@ get_default_user_units(void)
     gchar *e = _("default:mm");
   
 #ifdef HAVE_LANGINFO
+#ifdef _NL_MEASUREMENT_MEASUREMENT
     gchar *imperial = NULL;
   
     imperial = nl_langinfo(_NL_MEASUREMENT_MEASUREMENT);
     if (imperial && imperial[0] == 2 )
 	return GTK_UNIT_INCH;  /* imperial */
     if (imperial && imperial[0] == 1 )
+#endif
 	return GTK_UNIT_MM;  /* metric */
 #endif
   
