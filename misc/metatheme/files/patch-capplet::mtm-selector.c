
$FreeBSD$

--- capplet/mtm-selector.c	2001/07/10 06:15:32	1.1
+++ capplet/mtm-selector.c	2001/07/10 06:16:15
@@ -203,7 +203,7 @@
 
 	g_return_if_fail (MTM_IS_SELECTOR (selector));
 				   
-	sysdir  = g_strdup_printf ("%s/share/metathemes", mtm_get_prefix ());
+	sysdir  = g_strdup_printf ("%s/share/gnome/metathemes", mtm_get_prefix ());
 	userdir = g_strdup_printf ("%s/.metathemes", g_get_home_dir ());
      /* Create it if it doesn't exist */
 	mtm_check_dir (userdir);
