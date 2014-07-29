--- gtk/gtkrc.c.orig	Thu Mar 15 13:41:40 2001
+++ gtk/gtkrc.c	Fri Apr 16 00:24:54 2004
@@ -260,9 +260,9 @@
 
   var = getenv("GTK_DATA_PREFIX");
   if (var)
-    path = g_strdup_printf("%s%s", var, "/share/gtk/themes");
+    path = g_strdup_printf("%s%s", var, "/share/themes");
   else
-    path = g_strdup_printf("%s%s", GTK_DATA_PREFIX, "/share/gtk/themes");
+    path = g_strdup_printf("%s%s", GTK_DATA_PREFIX, "/share/themes");
   
   for (n = 0; pixmap_path[n]; n++) ;
   if (n >= GTK_RC_MAX_PIXMAP_PATHS - 1)
@@ -294,7 +294,7 @@
 
   var = g_get_home_dir ();
   if (var)
-    module_path[n++] = g_strdup_printf("%s%s", var, "/.gtk/lib/themes/engines");
+    module_path[n++] = g_strdup_printf("%s%s", var, "/.gtk/themes/engines");
   module_path[n] = NULL;
 }
 
@@ -312,6 +312,10 @@
   gtk_rc_default_files[0] = NULL;
   init = TRUE;
 
+  str = g_strdup_printf ("%s%s", GTK_SYSCONFDIR, "/gtkrc");
+  gtk_rc_add_default_file (str);
+  g_free (str);
+
   var = getenv("GTK_RC_FILES");
   if (var)
     {
@@ -326,10 +330,6 @@
     }
   else
     {
-      str = g_strdup_printf ("%s%s", GTK_SYSCONFDIR, "/gtk/gtkrc");
-      gtk_rc_add_default_file (str);
-      g_free (str);
-
       var = g_get_home_dir ();
       if (var)
 	{
