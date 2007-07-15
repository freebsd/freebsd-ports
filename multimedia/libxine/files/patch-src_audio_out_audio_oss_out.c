--- src/audio_out/audio_oss_out.c.orig	Mon Apr 16 02:42:15 2007
+++ src/audio_out/audio_oss_out.c	Sun Jul  1 14:42:59 2007
@@ -163,7 +163,7 @@
 		       uint32_t bits, uint32_t rate, int mode) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int tmp;
+  long tmp;
 
   xprintf(this->xine, XINE_VERBOSITY_DEBUG,
 	  "audio_oss_out: ao_open rate=%d, mode=%d, dev=%s\n", rate, mode, this->audio_dev);
@@ -295,14 +295,14 @@
       if (bits==8) {
 	xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: SNDCTL_DSP_SETFMT failed for AFMT_U8.\n");
         if (tmp != AFMT_U8)
-          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: ioctl succeeded but set format to 0x%x.\n",tmp);
+          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: ioctl succeeded but set format to 0x%lx.\n",tmp);
         else
           xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: The AFMT_U8 ioctl failed.\n");
         return 0;
       } else {
 	xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: SNDCTL_DSP_SETFMT failed for AFMT_S16_NE.\n");
         if (tmp != AFMT_S16_NE)
-          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: ioctl succeeded but set format to 0x%x.\n",tmp);
+          xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: ioctl succeeded but set format to 0x%lx.\n",tmp);
         else
           xprintf(this->xine, XINE_VERBOSITY_DEBUG, "audio_oss_out: The AFMT_S16_NE ioctl failed.\n");
         return 0;
@@ -321,7 +321,7 @@
     tmp = AFMT_AC3;
     if (ioctl(this->audio_fd, SNDCTL_DSP_SETFMT, &tmp) < 0 || tmp != AFMT_AC3) {
       xprintf(this->xine, XINE_VERBOSITY_DEBUG, 
-	      "audio_oss_out: AC3 SNDCTL_DSP_SETFMT failed. %d. Using alternative.\n",tmp);
+	      "audio_oss_out: AC3 SNDCTL_DSP_SETFMT failed. %ld. Using alternative.\n",tmp);
       tmp = AFMT_S16_LE;
       ioctl(this->audio_fd, SNDCTL_DSP_SETFMT, &tmp);
     }
@@ -377,7 +377,7 @@
 
   count_info    info;
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           bytes_left;
+  long          bytes_left;
   int           frames;
   struct        timeval tv;
 
@@ -515,7 +515,7 @@
 static int ao_oss_get_property (ao_driver_t *this_gen, int property) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           audio_devs;
+  long          audio_devs;
 
   switch(property) {
   case AO_PROP_PCM_VOL:
@@ -524,7 +524,7 @@
       
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v;
+	long v;
 	
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 	
@@ -554,7 +554,7 @@
 static int ao_oss_set_property (ao_driver_t *this_gen, int property, int value) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           audio_devs;
+  long          audio_devs;
 
   switch(property) {
   case AO_PROP_PCM_VOL:
@@ -563,7 +563,7 @@
       
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v;
+	long v;
 	
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 	
@@ -592,7 +592,7 @@
       
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v = 0;
+	long v = 0;
 	
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 	
@@ -665,7 +665,7 @@
 static int probe_audio_devices(oss_driver_t *this) {
   const char *base_names[2] = {"/dev/dsp", "/dev/sound/dsp"};
   int base_num, i;
-  int audio_fd, rate;
+  long audio_fd, rate;
   int best_rate;
   char devname[30];
 
@@ -704,9 +704,9 @@
   oss_class_t     *class = (oss_class_t *) class_gen;
   config_values_t *config = class->config;
   oss_driver_t    *this;
-  int              caps;
-  int              audio_fd;
-  int              num_channels, status, arg;
+  long             caps;
+  long             audio_fd;
+  long             num_channels, status, arg;
   static char     *sync_methods[] = {"auto", "getodelay", "getoptr", "softsync", "probebuffer", NULL};
   static char     *devname_opts[] = {"auto", "/dev/dsp", "/dev/sound/dsp", NULL};
   int devname_val, devname_num;
