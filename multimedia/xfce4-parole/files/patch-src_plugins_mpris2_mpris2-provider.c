--- src/plugins/mpris2/mpris2-provider.c.orig	2024-03-17 09:51:52 UTC
+++ src/plugins/mpris2/mpris2-provider.c
@@ -196,7 +196,7 @@ static GVariant* mpris_Root_get_SupportedUriSchemes(GE
 static GVariant* mpris_Root_get_SupportedUriSchemes(GError **error, Mpris2Provider *provider) {
     return g_variant_parse(G_VARIANT_TYPE("as"),
         "['cdda', 'dvd', 'file', 'icy', 'icyx', 'mms', 'mmsh', 'net', "
-        "'pnm', 'rtmp', 'rtp', 'rtsp', 'uvox']", NULL, NULL, NULL);
+        "'pnm', 'rtp', 'rtsp', 'uvox']", NULL, NULL, NULL);
 }
 
 static GVariant* mpris_Root_get_SupportedMimeTypes(GError **error, Mpris2Provider *provider) {
