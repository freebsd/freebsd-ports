--- src/guifications.c.orig	Sun Jul 11 13:22:37 2004
+++ src/guifications.c	Mon Aug  9 14:48:46 2004
@@ -402,7 +402,7 @@
 	g_object_unref(G_OBJECT(protocol_scaled));
 
 	if (gaim_prefs_get_bool(GF_PREF_BEHAVIOR_ALIAS))
-		name = g_strdup(gaim_get_buddy_alias(buddy));
+		name = g_strdup(gaim_buddy_get_alias(buddy));
 	else
 		name = g_strdup(buddy->name);
 	
