--- leif/sun_le_korea/auxwin_gtk/keyboard_config.c	Sat Mar 27 10:46:45 2004
+++ leif/sun_le_korea/auxwin_gtk/keyboard_config.c	Wed Feb 16 20:46:48 2005
@@ -432,7 +432,7 @@
     g_virtual_keyboards[i] = NULL;
 
   lang_name = (char *) strdup ("ko_KR");
-  sprintf(path_name, "/usr/lib/im/locale/%s", lang_name);
+  sprintf(path_name, IMDIR "/locale/%s", lang_name);
   free (lang_name);
 
 
