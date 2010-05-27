--- ./src/core/sipe.c.orig	2010-05-27 11:34:50.000000000 +0200
+++ ./src/core/sipe.c	2010-05-27 11:36:16.000000000 +0200
@@ -10683,6 +10683,8 @@
 	NULL,					/* get_media_caps */
 #if PURPLE_VERSION_CHECK(2,7,0)
 	NULL,					/* get_moods */
+	NULL,					/* set_public_alias */
+	NULL,					/* get_public_alias */
 #endif
 #endif
 #endif
