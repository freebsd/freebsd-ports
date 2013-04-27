--- ext/cdparanoia/gstcdparanoiasrc.c.orig	2009-08-09 17:16:48.000000000 -0400
+++ ext/cdparanoia/gstcdparanoiasrc.c	2009-08-09 17:17:38.000000000 -0400
@@ -264,6 +264,7 @@ gst_cd_paranoia_src_open (GstCddaBaseSrc
     GST_INFO_OBJECT (src, "search overlap set to %u", src->search_overlap);
   }
 
+#ifdef PARANOIA_CB_CACHEERR
   cache_size = src->cache_size;
   if (cache_size == -1) {
     /* if paranoia mode is low (the default), assume we're doing playback */
@@ -274,6 +275,7 @@ gst_cd_paranoia_src_open (GstCddaBaseSrc
   }
   paranoia_cachemodel_size (src->p, cache_size);
   GST_INFO_OBJECT (src, "set cachemodel size to %u", cache_size);
+#endif
 
   src->next_sector = -1;
 
