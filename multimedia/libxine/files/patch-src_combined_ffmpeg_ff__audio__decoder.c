--- src/combined/ffmpeg/ff_audio_decoder.c.orig	2022-09-08 21:43:29 UTC
+++ src/combined/ffmpeg/ff_audio_decoder.c
@@ -1,5 +1,5 @@
 /*
- * Copyright (C) 2001-2022 the xine project
+ * Copyright (C) 2001-2023 the xine project
  *
  * This file is part of xine, a free video player.
  *
@@ -303,7 +303,11 @@ static void ff_audio_init_codec(ff_audio_decoder_t *th
 
   this->context->bits_per_sample = this->ff_bits;
   this->context->sample_rate = this->ff_sample_rate;
+#if XFF_AUDIO_CHANNEL_LAYOUT < 2
   this->context->channels    = this->ff_channels;
+#else
+  this->context->ch_layout.nb_channels = this->ff_channels;
+#endif
   this->context->codec_id    = this->codec->id;
   this->context->codec_type  = this->codec->type;
   this->context->codec_tag   = _x_stream_info_get(this->stream, XINE_STREAM_INFO_AUDIO_FOURCC);
@@ -527,17 +531,76 @@ static void ff_audio_output_close(ff_audio_decoder_t *
   this->ao_mode = 0;
 }
 
+static unsigned int ff_list_channels (uint8_t *list, uint64_t map) {
+  unsigned int n, bit;
+
+  for (n = bit = 0; map; map >>= 1, bit++) {
+    uint32_t b = map & 1;
+
+    list[n] = bit;
+    n += b;
+  }
+  return n;
+}
+
 static void ff_map_channels (ff_audio_decoder_t *this) {
   uint64_t ff_map;
+  uint8_t ff_list[64];
+  unsigned int ff_num;
+  const char *type = "native";
   int caps = this->stream->audio_out->get_capabilities (this->stream->audio_out);
 
+#if XFF_AUDIO_CHANNEL_LAYOUT < 2
+
   /* safety kludge for very old libavcodec */
-#ifdef AV_CH_FRONT_LEFT
+#  ifdef AV_CH_FRONT_LEFT
   ff_map = this->context->channel_layout;
   if (!ff_map) /* wma2 bug */
-#endif
+#  endif
     ff_map = ((uint64_t)1 << this->context->channels) - 1;
+  ff_num = ff_list_channels (ff_list, ff_map);
 
+#else /* XFF_AUDIO_CHANNEL_LAYOUT == 2 */
+
+  ff_num = this->context->ch_layout.nb_channels;
+  if (ff_num > (int)(sizeof (ff_list) / sizeof (ff_list[0])))
+    ff_num = sizeof (ff_list) / sizeof (ff_list[0]);
+  switch (this->context->ch_layout.order) {
+    const AVChannelCustom *cmap;
+    unsigned int i;
+
+    case AV_CHANNEL_ORDER_UNSPEC:
+      type = "unknown";
+      goto _fallback;
+
+    case AV_CHANNEL_ORDER_NATIVE:
+      ff_map = this->context->ch_layout.u.mask;
+      if (!ff_map) /* wma2 bug */
+        ff_map = ((uint64_t)1 << ff_num) - 1;
+      ff_num = ff_list_channels (ff_list, ff_map);
+      break;
+
+    case AV_CHANNEL_ORDER_CUSTOM:
+      type = "custom";
+      if (!(cmap = this->context->ch_layout.u.map))
+        goto _fallback;
+      ff_map = 0;
+      for (i = 0; i < ff_num; i++) {
+        ff_list[i] = cmap[i].id;
+        ff_map |= (uint64_t)1 << ff_list[i];
+      }
+      break;
+
+    default:
+      type = "unsupported";
+      /* fall through */
+    _fallback:
+      ff_map = ((uint64_t)1 << ff_num) - 1;
+      ff_num = ff_list_channels (ff_list, ff_map);
+  }
+
+#endif
+
   if ((caps != this->ao_caps) || (ff_map != this->ff_map)) {
     unsigned int i, j;
     /* ff: see names[] below; xine: L R RL RR C LFE */
@@ -562,7 +625,7 @@ static void ff_map_channels (ff_audio_decoder_t *this)
 
     this->ao_caps     = caps;
     this->ff_map      = ff_map;
-    this->ff_channels = this->context->channels;
+    this->ff_channels = ff_num;
 
     /* silence out */
     for (i = 0; i < MAX_CHANNELS; i++)
@@ -576,20 +639,23 @@ static void ff_map_channels (ff_audio_decoder_t *this)
       this->left[0] = this->right[0] = 0;
       tries = wishlist + 0 * num_modes;
     } else if (this->ff_channels == 2) { /* stereo */
+      /* FIXME: libxine does not yet support audio selection _after_ decoding.
+       * For now, treat the most common "dual mono" case as stereo. */
       name_map[0] = 0;
       name_map[1] = 1;
       this->left[0] = 0;
       this->right[0] = 1;
       tries = wishlist + 1 * num_modes;
     } else {
-      for (i = j = 0; i < sizeof (base_map) / sizeof (base_map[0]); i++) {
-        if ((ff_map >> i) & 1) {
-          int8_t target = base_map[i];
-          if ((target >= 0) && (this->map[target] < 0))
-            this->map[target] = j;
-          name_map[j] = i; /* for debug output below */
-          j++;
-        }
+      for (i = 0; i < ff_num; i++) {
+        int8_t target;
+        uint32_t num = ff_list[i];
+        if (num >= sizeof (base_map) / sizeof (base_map[0]))
+          continue;
+        target = base_map[num];
+        if ((target >= 0) && (this->map[target] < 0))
+          this->map[target] = i;
+        name_map[i] = num; /* for debug output below */
       }
       this->left[0]  = this->map[0] < 0 ? 0 : this->map[0];
       this->map[0]   = -1;
@@ -641,8 +707,8 @@ static void ff_map_channels (ff_audio_decoder_t *this)
         "rear center",
         "side left", "side right"
       };
-      int8_t buf[200];
-      int p = sprintf (buf, "ff_audio_dec: channel layout: ");
+      int8_t buf[256];
+      int p = sprintf (buf, "ff_audio_dec: %s channel layout: ", type);
       int8_t *indx = this->left;
       for (i = 0; i < 2; i++) {
         buf[p++] = '[';
