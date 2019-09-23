--- libao2/ao_oss.c.orig	2016-02-26 20:47:16 UTC
+++ libao2/ao_oss.c
@@ -57,6 +57,8 @@ static const ao_info_t info =
 	""
 };
 
+static int volume = -1;
+
 /* Support for >2 output channels added 2001-11-25 - Steve Davies <steve@daviesfam.org> */
 
 LIBAO_EXTERN(oss)
@@ -73,6 +75,11 @@ static int format2oss(int format)
     case AF_FORMAT_S16_BE: return AFMT_S16_BE;
 #ifdef AFMT_S24_PACKED
     case AF_FORMAT_S24_LE: return AFMT_S24_PACKED;
+#elif defined(__FreeBSD__) && defined(AFMT_S24_LE)
+    case AF_FORMAT_U24_LE: return AFMT_U24_LE;
+    case AF_FORMAT_U24_BE: return AFMT_U24_BE;
+    case AF_FORMAT_S24_LE: return AFMT_S24_LE;
+    case AF_FORMAT_S24_BE: return AFMT_S24_BE;
 #endif
 #ifdef AFMT_U32_LE
     case AF_FORMAT_U32_LE: return AFMT_U32_LE;
@@ -116,6 +123,11 @@ static int oss2format(int format)
     case AFMT_S16_BE: return AF_FORMAT_S16_BE;
 #ifdef AFMT_S24_PACKED
     case AFMT_S24_PACKED: return AF_FORMAT_S24_LE;
+#elif defined(__FreeBSD__) && defined(AFMT_S24_LE)
+    case AFMT_U24_LE: return AF_FORMAT_U24_LE;
+    case AFMT_U24_BE: return AF_FORMAT_U24_BE;
+    case AFMT_S24_LE: return AF_FORMAT_S24_LE;
+    case AFMT_S24_BE: return AF_FORMAT_S24_BE;
 #endif
 #ifdef AFMT_U32_LE
     case AFMT_U32_LE: return AF_FORMAT_U32_LE;
@@ -217,6 +229,48 @@ static int control(int cmd,void *arg){
     return CONTROL_UNKNOWN;
 }
 
+static void setfragment(int audio_fd)
+{
+    int buffer_bytes = ao_data.channels * ao_data.samplerate;
+    int block_size = 0;
+
+    switch (ao_data.format & AF_FORMAT_BITS_MASK) {
+    case AF_FORMAT_8BIT:
+      break;
+    case AF_FORMAT_16BIT:
+      buffer_bytes *= 2;
+      break;
+    case AF_FORMAT_24BIT:
+      buffer_bytes *= 3;
+      break;
+    case AF_FORMAT_32BIT:
+      buffer_bytes *= 4;
+      break;
+    }
+    buffer_bytes *= 0.050;
+
+    if(ioctl(audio_fd, SNDCTL_DSP_GETBLKSIZE, &block_size)==0){
+      int setfrag;
+      /* make block size power of two */
+      while (block_size & (block_size - 1))
+         block_size += block_size & ~(block_size - 1);
+      /* set number of fragments */
+      setfrag = ((buffer_bytes + block_size - 1) / block_size) << 16;
+      /* need at least double buffering */
+      if (setfrag < (2 << 16))
+        setfrag = (2 << 16);
+      /* set block size in power of two */
+      while (block_size) {
+        setfrag++;
+        block_size /= 2;
+      }
+      /* try to set a total buffer of 50ms */
+      if (ioctl(audio_fd, SNDCTL_DSP_SETFRAGMENT, &setfrag)==-1){
+        mp_msg(MSGT_AO,MSGL_V,"audio_setup: setfragment %d failed\n", setfrag);
+      }
+    }
+}
+
 // open & setup audio device
 // return: 1=success 0=fail
 static int init(int rate,int channels,int format,int flags){
@@ -364,6 +418,7 @@ ac3_retry:
       mp_msg(MSGT_AO,MSGL_WARN, "OSS: Failed setting sample-rate %i %s\n", rate, strerror(errno));
     mp_msg(MSGT_AO,MSGL_V,"audio_setup: using %d Hz samplerate (requested: %d)\n",ao_data.samplerate,rate);
   }
+  setfragment(audio_fd);
 
   if(ioctl(audio_fd, SNDCTL_DSP_GETOSPACE, &zz)==-1){
       int r=0;
@@ -441,10 +496,30 @@ static void uninit(int immed){
     audio_fd = -1;
 }
 
+static void savevol(void){
+	int fd;
+	if (volume < 0) {
+		if ((fd = open(oss_mixer_device, O_RDONLY)) >= 0) { 
+			ioctl(fd, MIXER_READ(oss_mixer_channel), &volume);
+			close(fd);
+		}
+	}     
+}
+
+static void restorevol(void){
+	int fd;
+	if ((fd = open(oss_mixer_device, O_RDONLY)) >= 0) {
+		ioctl(fd, MIXER_WRITE(oss_mixer_channel), &volume);
+		close(fd);
+	}
+	volume = -1;     
+}
+
 // stop playing and empty buffers (for seeking/pause)
 static void reset(void){
   int fail = 0;
   int oss_format;
+    savevol();
     uninit(1);
     audio_fd=open(dsp, O_WRONLY);
     if(audio_fd < 0){
@@ -456,6 +531,7 @@ static void reset(void){
   fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
 #endif
 
+  ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   oss_format = format2oss(ao_data.format);
   if(AF_FORMAT_IS_AC3(ao_data.format))
     fail |= ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate) == -1;
@@ -467,14 +543,15 @@ static void reset(void){
       int c = ao_data.channels-1;
       fail |= ioctl (audio_fd, SNDCTL_DSP_STEREO, &c) == -1;
     }
-    fail |= ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate) == -1;
   }
-  mp_msg(MSGT_AO,MSGL_WARN, "OSS: Reset failed\n");
+  setfragment(audio_fd);
+  restorevol();
 }
 
 // stop playing, keep buffers (for pause)
 static void audio_pause(void)
 {
+    savevol();
     prepause_space = get_space();
     uninit(1);
 }
