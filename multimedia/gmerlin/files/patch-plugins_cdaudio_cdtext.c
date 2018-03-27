Fix build with sysutils/libcdio >= 0.90

--- plugins/cdaudio/cdtext.c.orig	2012-06-08 11:50:33 UTC
+++ plugins/cdaudio/cdtext.c
@@ -34,7 +34,7 @@
 #include "cdaudio.h"
 
 #define GET_FIELD(dst, key) \
-  field = cdtext_get_const(key, cdtext);
+  field = cdtext_get_const(cdtext, key, i+1);
 
 #define GET_FIELD_DEFAULT(dst,key)                                      \
   field = cdtext_get_const(key, cdtext);                                \
@@ -64,38 +64,34 @@ int bg_cdaudio_get_metadata_cdtext(CdIo_t * cdio,
 
   /* Get information for the whole disc */
   
-  cdtext = cdio_get_cdtext (cdio, 0);
+  cdtext = cdio_get_cdtext (cdio);
 
   if(!cdtext)
     return 0;
   
-  artist  = cdtext_get_const(CDTEXT_PERFORMER, cdtext);
-  author  = cdtext_get_const(CDTEXT_COMPOSER, cdtext); /* Composer overwrites songwriter */
+  artist  = cdtext_get_const(cdtext, CDTEXT_FIELD_PERFORMER, 0);
+  author  = cdtext_get_const(cdtext, CDTEXT_FIELD_COMPOSER, 0); /* Composer overwrites songwriter */
 
   if(!author)
-    author  = cdtext_get_const(CDTEXT_SONGWRITER, cdtext);
+    author  = cdtext_get_const(cdtext, CDTEXT_FIELD_SONGWRITER, 0);
   
-  album  = cdtext_get_const(CDTEXT_TITLE, cdtext);
-  genre  = cdtext_get_const(CDTEXT_GENRE, cdtext);
-  comment  = cdtext_get_const(CDTEXT_MESSAGE, cdtext);
+  album  = cdtext_get_const(cdtext, CDTEXT_FIELD_TITLE, 0);
+  genre  = cdtext_get_const(cdtext, CDTEXT_FIELD_GENRE, 0);
+  comment  = cdtext_get_const(cdtext, CDTEXT_FIELD_MESSAGE, 0);
   
   for(i = 0; i < idx->num_tracks; i++)
     {
     if(idx->tracks[i].is_audio)
       {
-      cdtext = cdio_get_cdtext (cdio, i+1);
-      if(!cdtext)
-        return 0;
+      GET_FIELD(title, CDTEXT_FIELD_TITLE);
       
-      GET_FIELD(title, CDTEXT_TITLE);
-      
       if(!title)
         return 0;
 
       gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                         GAVL_META_TITLE, title);
 
-      if((field = cdtext_get_const(CDTEXT_PERFORMER, cdtext)))
+      if((field = cdtext_get_const(cdtext, CDTEXT_FIELD_PERFORMER, i+1)))
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_ARTIST, field);
       else
@@ -103,10 +99,10 @@ int bg_cdaudio_get_metadata_cdtext(CdIo_t * cdio,
                           GAVL_META_ARTIST, artist);
 
 
-      if((field = cdtext_get_const(CDTEXT_COMPOSER, cdtext)))
+      if((field = cdtext_get_const(cdtext, CDTEXT_FIELD_COMPOSER, i+1)))
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_AUTHOR, field);
-      else if((field = cdtext_get_const(CDTEXT_SONGWRITER, cdtext)))
+      else if((field = cdtext_get_const(cdtext, CDTEXT_FIELD_SONGWRITER, i+1)))
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_AUTHOR, field);
       else if(author)
@@ -114,14 +110,14 @@ int bg_cdaudio_get_metadata_cdtext(CdIo_t * cdio,
                           GAVL_META_AUTHOR, author);
 
 
-      if((field = cdtext_get_const(CDTEXT_GENRE, cdtext)))
+      if((field = cdtext_get_const(cdtext, CDTEXT_FIELD_GENRE, i+1)))
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_GENRE, field);
       else
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_GENRE, genre);
 
-      if((field = cdtext_get_const(CDTEXT_MESSAGE, cdtext)))
+      if((field = cdtext_get_const(cdtext, CDTEXT_FIELD_MESSAGE, i+1)))
         gavl_metadata_set(&info[idx->tracks[i].index].metadata,
                           GAVL_META_COMMENT, field);
       else
