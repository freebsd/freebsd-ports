--- capplet/mtm-selector.c.orig	Sun May 19 17:05:01 2002
+++ capplet/mtm-selector.c	Sun May 19 17:05:11 2002
@@ -209,7 +209,7 @@
 
 	g_return_if_fail (MTM_IS_SELECTOR (selector));
 				   
-	sysdir  = g_strdup_printf ("%s/share/metathemes", mtm_get_prefix ());
+	sysdir  = g_strdup_printf ("%s/share/gnome/metathemes", mtm_get_prefix ());
 	userdir = g_strdup_printf ("%s/.metathemes", g_get_home_dir ());
      /* Create it if it doesn't exist */
 	mtm_check_dir (userdir);
