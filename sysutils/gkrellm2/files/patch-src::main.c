--- src/main.c.orig	2008-10-11 13:03:40.000000000 -0600
+++ src/main.c	2008-10-11 13:04:17.000000000 -0600
@@ -2050,6 +2050,8 @@
 	gint		i;
 	gchar		*s;
 
+	gkrellm_sys_main_init(); //FIXME: call this later or earlier?
+
 #ifdef ENABLE_NLS
 	gtk_set_locale();
 #endif
@@ -2189,8 +2191,6 @@
 		g_debug("--- GKrellM %d.%d.%d ---\n", GKRELLM_VERSION_MAJOR,
 			GKRELLM_VERSION_MINOR, GKRELLM_VERSION_REV);
 
-	gkrellm_sys_main_init(); //FIXME: call this later or earlier?
-
 	_GK.w_display = gdk_screen_get_width(gdk_screen_get_default());
 	_GK.h_display = gdk_screen_get_height(gdk_screen_get_default());
 
