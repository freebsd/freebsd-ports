--- ./Output/alsa/audio.c.orig	2012-11-01 11:14:01.000000000 -0400
+++ ./Output/alsa/audio.c	2012-11-01 11:15:25.000000000 -0400
@@ -47,7 +47,7 @@
 static snd_mixer_elem_t *pcm_element = NULL;
 static snd_mixer_t *mixer = NULL;
 
-static gboolean mmap, going = FALSE, paused, multi_thread, mixer_start = TRUE;;
+static gboolean mmap_bool, going = FALSE, paused, multi_thread, mixer_start = TRUE;;
 
 static gboolean alsa_can_pause;
 
@@ -691,7 +691,7 @@
     if (alsa_cfg.soft_volume)
         volume_adjust(data, length, outputf->xmms_format, outputf->channels);
 
-    if (mmap)
+    if (mmap_bool)
         alsa_mmap_audio(data, length);
     else
         alsa_write_audio(data, length);
@@ -900,7 +900,7 @@
     if (alsa_cfg.debug)
         snd_output_stdio_attach(&logs, stdout, 0);
 
-    mmap = alsa_cfg.mmap;
+    mmap_bool = alsa_cfg.mmap;
 
     if (alsa_setup(inputf) < 0) {
         alsa_close();
@@ -1036,16 +1036,16 @@
         return -1;
     }
 
-    if (mmap &&
+    if (mmap_bool &&
         (err = snd_pcm_hw_params_set_access(alsa_pcm, hwparams,
                                             SND_PCM_ACCESS_MMAP_INTERLEAVED))
         < 0) {
         g_message("alsa_setup(): Cannot set mmap'ed mode: %s. "
                   "falling back to direct write", snd_strerror(-err));
-        mmap = 0;
+        mmap_bool = 0;
     }
 
-    if (!mmap &&
+    if (!mmap_bool &&
         (err = snd_pcm_hw_params_set_access(alsa_pcm, hwparams,
                                             SND_PCM_ACCESS_RW_INTERLEAVED)) <
         0) {
