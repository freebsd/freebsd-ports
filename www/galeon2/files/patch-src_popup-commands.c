--- src/popup-commands.c.orig	Tue Aug 10 00:31:14 2004
+++ src/popup-commands.c	Tue Aug 10 00:31:21 2004
@@ -333,11 +333,11 @@
 			GaleonPopup *popup)
 {
 	GaleonEmbed *embed;
+	char *location;
 
 	embed = galeon_popup_get_embed (popup);
 	g_return_if_fail (GALEON_IS_EMBED (embed));
 		
-	char *location;
 	galeon_embed_get_location (embed, FALSE, FALSE, &location);
 	popup_copy_to_clipboard (popup, location);
 	g_free (location);
