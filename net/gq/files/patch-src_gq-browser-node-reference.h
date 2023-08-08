--- src/gq-browser-node-reference.h.orig	2023-04-11 01:15:02 UTC
+++ src/gq-browser-node-reference.h
@@ -51,7 +51,7 @@ struct _GqBrowserNodeReference {
 	char *uri;
 	GqServer *server;
 	gboolean expanded;
-} ref_browse_entry;
+};
 
 G_END_DECLS
 
