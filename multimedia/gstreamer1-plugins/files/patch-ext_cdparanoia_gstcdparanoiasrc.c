--- ext/cdparanoia/gstcdparanoiasrc.c.orig	2026-01-27 17:02:33 UTC
+++ ext/cdparanoia/gstcdparanoiasrc.c
@@ -262,6 +262,7 @@ gst_cd_paranoia_src_open (GstAudioCdSrc * audiocdsrc, 
     GST_INFO_OBJECT (src, "search overlap set to %u", src->search_overlap);
   }
 
+#ifdef PARANOIA_CB_CACHEERR
   cache_size = src->cache_size;
   if (cache_size == -1) {
     /* if paranoia mode is low (the default), assume we're doing playback */
@@ -272,6 +273,7 @@ gst_cd_paranoia_src_open (GstAudioCdSrc * audiocdsrc, 
   }
   paranoia_cachemodel_size (src->p, cache_size);
   GST_INFO_OBJECT (src, "set cachemodel size to %u", cache_size);
+#endif
 
   src->next_sector = -1;
 
