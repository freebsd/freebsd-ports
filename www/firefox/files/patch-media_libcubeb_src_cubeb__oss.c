--- media/libcubeb/src/cubeb_oss.c.orig	2021-11-17 19:30:43 UTC
+++ media/libcubeb/src/cubeb_oss.c
@@ -96,6 +96,9 @@ struct oss_stream {
   oss_devnode_t name;
   int fd;
   void * buf;
+  unsigned int nfr; /* Number of frames allocated */
+  unsigned int nfrags;
+  unsigned int bufframes;
 
   struct stream_info {
     int channels;
@@ -126,9 +129,6 @@ struct cubeb_stream {
   cubeb_data_callback data_cb;
   cubeb_state_callback state_cb;
   uint64_t frames_written /* (m) */;
-  unsigned int nfr; /* Number of frames allocated */
-  unsigned int nfrags;
-  unsigned int bufframes;
 };
 
 static char const *
@@ -786,40 +786,51 @@ oss_put_play_frames(cubeb_stream * s, unsigned int nfr
 }
 
 static int
-oss_wait_playfd_for_space(cubeb_stream * s)
+oss_wait_fds_for_space(cubeb_stream * s, long * nfrp)
 {
-  struct pollfd pfd;
+  audio_buf_info bi;
+  struct pollfd pfds[2];
+  long nfr = LONG_MAX, tnfr;
+  int i = 0;
 
-  pfd.events = POLLOUT | POLLHUP;
-  pfd.revents = 0;
-  pfd.fd = s->play.fd;
+  assert(s->play.fd != -1 || s->record.fd != -1);
+  pfds[0].events = POLLOUT | POLLHUP;
+  pfds[0].revents = 0;
+  pfds[0].fd = s->play.fd;
+  pfds[1].events = POLLIN | POLLHUP;
+  pfds[1].revents = 0;
+  pfds[1].fd = s->record.fd;
 
-  if (poll(&pfd, 1, 2000) == -1) {
+  if (poll(pfds, 2, 1000) == -1) {
     return CUBEB_ERROR;
   }
 
-  if (pfd.revents & POLLHUP) {
-    return CUBEB_ERROR;
+  for (i = 0; i < 2; i++) {
+    if (pfds[i].revents & POLLHUP) {
+      return CUBEB_ERROR;
+    }
   }
-  return 0;
-}
 
-static int
-oss_wait_recfd_for_space(cubeb_stream * s)
-{
-  struct pollfd pfd;
-
-  pfd.events = POLLIN | POLLHUP;
-  pfd.revents = 0;
-  pfd.fd = s->record.fd;
-
-  if (poll(&pfd, 1, 2000) == -1) {
-    return CUBEB_ERROR;
+  if (s->play.fd != -1) {
+    if (ioctl(s->play.fd, SNDCTL_DSP_GETOSPACE, &bi) == -1) {
+      return CUBEB_STATE_ERROR;
+    }
+    tnfr = bi.bytes / s->play.frame_size;
+    if (nfr > tnfr) {
+      nfr = tnfr;
+    }
   }
-
-  if (pfd.revents & POLLHUP) {
-    return CUBEB_ERROR;
+  if (s->record.fd != -1) {
+    if (ioctl(s->record.fd, SNDCTL_DSP_GETISPACE, &bi) == -1) {
+      return CUBEB_STATE_ERROR;
+    }
+    tnfr = bi.bytes / s->record.frame_size;
+    if (nfr > tnfr) {
+      nfr = tnfr;
+    }
   }
+
+  *nfrp = nfr;
   return 0;
 }
 
@@ -840,7 +851,7 @@ oss_audio_loop(cubeb_stream * s, cubeb_state * new_sta
     }
 
     trig |= PCM_ENABLE_INPUT;
-    memset(s->record.buf, 0, s->bufframes * s->record.frame_size);
+    memset(s->record.buf, 0, s->record.bufframes * s->record.frame_size);
 
     if (ioctl(s->record.fd, SNDCTL_DSP_SETTRIGGER, &trig) == -1) {
       LOG("Error %d occured when setting trigger on record fd", errno);
@@ -877,6 +888,7 @@ oss_audio_loop(cubeb_stream * s, cubeb_state * new_sta
           oss_linear32_to_float(s->record.buf, s->record.info.channels * nfr);
         }
       }
+
       got = s->data_cb(s, s->user_ptr, s->record.buf, s->play.buf, nfr);
       if (got == CUBEB_ERROR) {
         state = CUBEB_STATE_ERROR;
@@ -920,45 +932,10 @@ oss_audio_loop(cubeb_stream * s, cubeb_state * new_sta
       }
     }
 
-    nfr = s->bufframes;
-
-    if (record_on) {
-      long mfr;
-
-      if (oss_wait_recfd_for_space(s) != 0) {
-        state = CUBEB_STATE_ERROR;
-        goto breakdown;
-      }
-
-      audio_buf_info bi;
-      if (ioctl(s->record.fd, SNDCTL_DSP_GETISPACE, &bi) == -1) {
-        state = CUBEB_STATE_ERROR;
-        goto breakdown;
-      }
-
-      mfr = (bi.fragsize * bi.fragments) / s->record.frame_size;
-      if (nfr > mfr)
-        nfr = mfr;
+    if (oss_wait_fds_for_space(s, &nfr) != 0) {
+      state = CUBEB_STATE_ERROR;
+      goto breakdown;
     }
-
-    if (play_on) {
-      long mfr;
-
-      if (oss_wait_playfd_for_space(s) != 0) {
-        state = CUBEB_STATE_ERROR;
-        goto breakdown;
-      }
-
-      audio_buf_info bi;
-      if (ioctl(s->play.fd, SNDCTL_DSP_GETOSPACE, &bi) == -1) {
-        state = CUBEB_STATE_ERROR;
-        goto breakdown;
-      }
-
-      mfr = (bi.fragsize * bi.fragments) / s->play.frame_size;
-      if (nfr > mfr)
-        nfr = mfr;
-    }
   }
 
   return 1;
@@ -1015,9 +992,10 @@ static inline int
 oss_calc_frag_shift(unsigned int frames, unsigned int frame_size)
 {
   int n = 4;
-  int blksize = (frames * frame_size + OSS_NFRAGS - 1) / OSS_NFRAGS;
-  while ((1 << n) < blksize)
+  int blksize = frames * frame_size;
+  while ((1 << n) < blksize) {
     n++;
+  }
   return n;
 }
 
@@ -1037,7 +1015,6 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
                 cubeb_state_callback state_callback, void * user_ptr)
 {
   int ret = CUBEB_OK;
-  unsigned int playnfr = 0, recnfr = 0;
   cubeb_stream * s = NULL;
   const char * defdsp;
 
@@ -1051,7 +1028,6 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
   }
   s->state = CUBEB_STATE_STOPPED;
   s->record.fd = s->play.fd = -1;
-  s->nfr = latency_frames;
   if (input_device != NULL) {
     strlcpy(s->record.name, input_device, sizeof(s->record.name));
   } else {
@@ -1077,13 +1053,11 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
       ret = CUBEB_ERROR_INVALID_PARAMETER;
       goto error;
     }
-    if (s->record.fd == -1) {
-      if ((s->record.fd = open(s->record.name, O_RDONLY)) == -1) {
-        LOG("Audio device \"%s\" could not be opened as read-only",
-            s->record.name);
-        ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
-        goto error;
-      }
+    if ((s->record.fd = open(s->record.name, O_RDONLY)) == -1) {
+      LOG("Audio device \"%s\" could not be opened as read-only",
+          s->record.name);
+      ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
+      goto error;
     }
     if ((ret = oss_copy_params(s->record.fd, s, input_stream_params,
                                &s->record.info)) != CUBEB_OK) {
@@ -1094,8 +1068,15 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
         (input_stream_params->format == CUBEB_SAMPLE_FLOAT32NE);
     s->record.frame_size =
         s->record.info.channels * (s->record.info.precision / 8);
-    recnfr = (1 << oss_calc_frag_shift(s->nfr, s->record.frame_size)) /
-             s->record.frame_size;
+    s->record.nfrags = OSS_NFRAGS;
+    s->record.nfr = latency_frames / OSS_NFRAGS;
+    s->record.bufframes = s->record.nfrags * s->record.nfr;
+    uint32_t minnfr;
+    oss_get_min_latency(context, *input_stream_params, &minnfr);
+    if (s->record.nfr < minnfr) {
+      s->record.nfr = minnfr;
+      s->record.nfrags = latency_frames / minnfr;
+    }
   }
   if (output_stream_params != NULL) {
     unsigned int nb_channels;
@@ -1113,13 +1094,11 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
       ret = CUBEB_ERROR_INVALID_PARAMETER;
       goto error;
     }
-    if (s->play.fd == -1) {
-      if ((s->play.fd = open(s->play.name, O_WRONLY)) == -1) {
-        LOG("Audio device \"%s\" could not be opened as write-only",
-            s->play.name);
-        ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
-        goto error;
-      }
+    if ((s->play.fd = open(s->play.name, O_WRONLY)) == -1) {
+      LOG("Audio device \"%s\" could not be opened as write-only",
+          s->play.name);
+      ret = CUBEB_ERROR_DEVICE_UNAVAILABLE;
+      goto error;
     }
     if ((ret = oss_copy_params(s->play.fd, s, output_stream_params,
                                &s->play.info)) != CUBEB_OK) {
@@ -1128,19 +1107,19 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
     }
     s->play.floating = (output_stream_params->format == CUBEB_SAMPLE_FLOAT32NE);
     s->play.frame_size = s->play.info.channels * (s->play.info.precision / 8);
-    playnfr = (1 << oss_calc_frag_shift(s->nfr, s->play.frame_size)) /
-              s->play.frame_size;
+    s->play.nfrags = OSS_NFRAGS;
+    s->play.nfr = latency_frames / OSS_NFRAGS;
+    uint32_t minnfr;
+    oss_get_min_latency(context, *output_stream_params, &minnfr);
+    if (s->play.nfr < minnfr) {
+      s->play.nfr = minnfr;
+      s->play.nfrags = latency_frames / minnfr;
+    }
+    s->play.bufframes = s->play.nfrags * s->play.nfr;
   }
-  /*
-   * Use the largest nframes among playing and recording streams to set OSS
-   * buffer size. After that, use the smallest allocated nframes among both
-   * direction to allocate our temporary buffers.
-   */
-  s->nfr = (playnfr > recnfr) ? playnfr : recnfr;
-  s->nfrags = OSS_NFRAGS;
   if (s->play.fd != -1) {
-    int frag =
-        oss_get_frag_params(oss_calc_frag_shift(s->nfr, s->play.frame_size));
+    int frag = oss_get_frag_params(
+        oss_calc_frag_shift(s->play.nfr, s->play.frame_size));
     if (ioctl(s->play.fd, SNDCTL_DSP_SETFRAGMENT, &frag))
       LOG("Failed to set play fd with SNDCTL_DSP_SETFRAGMENT. frag: 0x%x",
           frag);
@@ -1148,13 +1127,19 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
     if (ioctl(s->play.fd, SNDCTL_DSP_GETOSPACE, &bi))
       LOG("Failed to get play fd's buffer info.");
     else {
-      if (bi.fragsize / s->play.frame_size < s->nfr)
-        s->nfr = bi.fragsize / s->play.frame_size;
+      s->play.nfr = bi.fragsize / s->play.frame_size;
+      s->play.nfrags = bi.fragments;
+      s->play.bufframes = s->play.nfr * s->play.nfrags;
     }
+
+    int lw = s->play.frame_size;
+    if (ioctl(s->play.fd, SNDCTL_DSP_LOW_WATER, &lw))
+      LOG("Audio device \"%s\" (play) could not set trigger threshold",
+          s->play.name);
   }
   if (s->record.fd != -1) {
-    int frag =
-        oss_get_frag_params(oss_calc_frag_shift(s->nfr, s->record.frame_size));
+    int frag = oss_get_frag_params(
+        oss_calc_frag_shift(s->record.nfr, s->record.frame_size));
     if (ioctl(s->record.fd, SNDCTL_DSP_SETFRAGMENT, &frag))
       LOG("Failed to set record fd with SNDCTL_DSP_SETFRAGMENT. frag: 0x%x",
           frag);
@@ -1162,11 +1147,16 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
     if (ioctl(s->record.fd, SNDCTL_DSP_GETISPACE, &bi))
       LOG("Failed to get record fd's buffer info.");
     else {
-      if (bi.fragsize / s->record.frame_size < s->nfr)
-        s->nfr = bi.fragsize / s->record.frame_size;
+      s->record.nfr = bi.fragsize / s->record.frame_size;
+      s->record.nfrags = bi.fragments;
+      s->record.bufframes = s->record.nfr * s->record.nfrags;
     }
+
+    int lw = s->record.frame_size;
+    if (ioctl(s->record.fd, SNDCTL_DSP_LOW_WATER, &lw))
+      LOG("Audio device \"%s\" (record) could not set trigger threshold",
+          s->record.name);
   }
-  s->bufframes = s->nfr * s->nfrags;
   s->context = context;
   s->volume = 1.0;
   s->state_cb = state_callback;
@@ -1188,13 +1178,14 @@ oss_stream_init(cubeb * context, cubeb_stream ** strea
   s->doorbell = false;
 
   if (s->play.fd != -1) {
-    if ((s->play.buf = calloc(s->bufframes, s->play.frame_size)) == NULL) {
+    if ((s->play.buf = calloc(s->play.bufframes, s->play.frame_size)) == NULL) {
       ret = CUBEB_ERROR;
       goto error;
     }
   }
   if (s->record.fd != -1) {
-    if ((s->record.buf = calloc(s->bufframes, s->record.frame_size)) == NULL) {
+    if ((s->record.buf = calloc(s->record.bufframes, s->record.frame_size)) ==
+        NULL) {
       ret = CUBEB_ERROR;
       goto error;
     }
