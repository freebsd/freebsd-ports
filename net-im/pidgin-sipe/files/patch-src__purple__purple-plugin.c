--- ./src/purple/purple-plugin.c.orig	2010-11-03 05:13:51.000000000 +0100
+++ ./src/purple/purple-plugin.c	2011-06-21 11:23:35.000000000 +0200
@@ -506,6 +506,10 @@
 	NULL,					/* get_moods */
 	NULL,					/* set_public_alias */
 	NULL,					/* get_public_alias */
+#if PURPLE_VERSION_CHECK(2,8,0)
+	NULL,					/* add_buddy_with_invite */
+	NULL,					/* add_buddies_with_invite */
+#endif
 #endif
 #endif
 #endif
