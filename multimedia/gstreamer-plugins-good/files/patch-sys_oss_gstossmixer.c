--- sys/oss/gstossmixer.c.bak	2006-08-16 05:25:17.000000000 -0400
+++ sys/oss/gstossmixer.c	2008-12-24 00:27:14.000000000 -0500
@@ -146,7 +146,7 @@ gst_ossmixer_ensure_track_list (GstOssMi
 
       /* do we want this in our list? */
       if (!((mixer->dir & GST_OSS_MIXER_CAPTURE && input == TRUE) ||
-              (mixer->dir & GST_OSS_MIXER_PLAYBACK && i != SOUND_MIXER_PCM)))
+              (mixer->dir & GST_OSS_MIXER_PLAYBACK)))
         /* the PLAYBACK case seems hacky, but that's how 0.8 had it */
         continue;
 
