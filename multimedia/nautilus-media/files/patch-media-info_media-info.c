--- media-info/media-info.c.orig	Tue Aug 12 15:08:26 2003
+++ media-info/media-info.c	Tue Aug 12 15:08:53 2003
@@ -258,10 +258,11 @@
 gboolean
 gst_media_info_read_idler (GstMediaInfo *info, GstMediaInfoStream **streamp)
 {
+  GstMediaInfoPriv *priv;
   /* if it's NULL then we're sure something went wrong higher up) */
   if (info == NULL) return FALSE;
 
-  GstMediaInfoPriv *priv = info->priv;
+  priv = info->priv;
 
   g_assert (streamp != NULL);
   switch (priv->state)
