--- libao2/ao_oss.c.orig	2010-01-11 21:27:52.000000000 +0100
+++ libao2/ao_oss.c	2011-12-29 01:06:49.227522915 +0100
@@ -56,6 +56,8 @@
 	""
 };
 
+static int volume = -1;
+
 /* Support for >2 output channels added 2001-11-25 - Steve Davies <steve@daviesfam.org> */
 
 LIBAO_EXTERN(oss)
@@ -72,6 +74,11 @@
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
@@ -115,6 +122,11 @@
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
@@ -434,9 +446,29 @@
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
   int oss_format;
+    savevol();
     uninit(1);
     audio_fd=open(dsp, O_WRONLY);
     if(audio_fd < 0){
@@ -448,6 +480,7 @@
   fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
 #endif
 
+  ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   oss_format = format2oss(ao_data.format);
   if(AF_FORMAT_IS_AC3(ao_data.format))
     ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
@@ -459,13 +492,14 @@
       int c = ao_data.channels-1;
       ioctl (audio_fd, SNDCTL_DSP_STEREO, &c);
     }
-    ioctl (audio_fd, SNDCTL_DSP_SPEED, &ao_data.samplerate);
   }
+  restorevol();
 }
 
 // stop playing, keep buffers (for pause)
 static void audio_pause(void)
 {
+	savevol();
     prepause_space = get_space();
     uninit(1);
 }
