--- lib/demux_ffmpeg.c.orig	2012-06-08 13:51:34.000000000 +0200
+++ lib/demux_ffmpeg.c	2012-07-22 00:23:38.489505138 +0200
@@ -774,15 +774,17 @@
   
   /* Metadata */
   if(avfc->title[0])
-    ctx->tt->cur->metadata.title = bgav_strdup(avfc->title);
+    gavl_metadata_set(&ctx->tt->cur->metadata, GAVL_META_TITLE, avfc->title);
   if(avfc->author[0])
-    ctx->tt->cur->metadata.author = bgav_strdup(avfc->author);
+    gavl_metadata_set(&ctx->tt->cur->metadata, GAVL_META_AUTHOR, avfc->author);
   if(avfc->copyright[0])
-    ctx->tt->cur->metadata.copyright = bgav_strdup(avfc->copyright);
+    gavl_metadata_set(&ctx->tt->cur->metadata, GAVL_META_COPYRIGHT, avfc->copyright);
   if(avfc->album[0])
-    ctx->tt->cur->metadata.album = bgav_strdup(avfc->album);
+    gavl_metadata_set(&ctx->tt->cur->metadata, GAVL_META_ALBUM, avfc->album);
   if(avfc->genre[0])
-    ctx->tt->cur->metadata.genre = bgav_strdup(avfc->genre);
+    gavl_metadata_set(&ctx->tt->cur->metadata, GAVL_META_GENRE, avfc->genre);
+  if(avfc->track)
+    gavl_metadata_set_int(&ctx->tt->cur->metadata, GAVL_META_TRACKNUMBER, avfc->track);
 
 #endif
 
