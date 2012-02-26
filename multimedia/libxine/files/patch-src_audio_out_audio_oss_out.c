--- ./src/audio_out/audio_oss_out.c.orig
+++ ./src/audio_out/audio_oss_out.c
@@ -159,7 +159,7 @@ static int ao_oss_open(ao_driver_t *this
 		       uint32_t bits, uint32_t rate, int mode) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int tmp;
+  long tmp;
 
   xprintf(this->xine, XINE_VERBOSITY_DEBUG,
 	  "audio_oss_out: ao_open rate=%d, mode=%d, dev=%s\n", rate, mode, this->audio_dev);
@@ -291,14 +291,14 @@ static int ao_oss_open(ao_driver_t *this
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
@@ -317,7 +317,7 @@ static int ao_oss_open(ao_driver_t *this
     tmp = AFMT_AC3;
     if (ioctl(this->audio_fd, SNDCTL_DSP_SETFMT, &tmp) < 0 || tmp != AFMT_AC3) {
       xprintf(this->xine, XINE_VERBOSITY_DEBUG,
-	      "audio_oss_out: AC3 SNDCTL_DSP_SETFMT failed. %d. Using alternative.\n",tmp);
+	      "audio_oss_out: AC3 SNDCTL_DSP_SETFMT failed. %ld. Using alternative.\n",tmp);
       tmp = AFMT_S16_LE;
       ioctl(this->audio_fd, SNDCTL_DSP_SETFMT, &tmp);
     }
@@ -373,7 +373,7 @@ static int ao_oss_delay(ao_driver_t *thi
 
   count_info    info;
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           bytes_left = 0;
+  long          bytes_left = 0;
   int           frames;
   struct        timeval tv;
 
@@ -512,7 +512,7 @@ static void ao_oss_exit(ao_driver_t *thi
 static int ao_oss_get_property (ao_driver_t *this_gen, int property) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           audio_devs;
+  long          audio_devs;
 
   switch(property) {
   case AO_PROP_PCM_VOL:
@@ -521,7 +521,7 @@ static int ao_oss_get_property (ao_drive
 
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v;
+	long v;
 
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 
@@ -551,7 +551,7 @@ static int ao_oss_get_property (ao_drive
 static int ao_oss_set_property (ao_driver_t *this_gen, int property, int value) {
 
   oss_driver_t *this = (oss_driver_t *) this_gen;
-  int           audio_devs;
+  long          audio_devs;
 
   switch(property) {
   case AO_PROP_PCM_VOL:
@@ -560,7 +560,7 @@ static int ao_oss_set_property (ao_drive
 
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v;
+	long v;
 
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 
@@ -589,7 +589,7 @@ static int ao_oss_set_property (ao_drive
 
       if(this->mixer.fd != -1) {
 	IOCTL_REQUEST_TYPE cmd = 0;
-	int v = 0;
+	long v = 0;
 
 	ioctl(this->mixer.fd, SOUND_MIXER_READ_DEVMASK, &audio_devs);
 
@@ -662,7 +662,7 @@ static int ao_oss_ctrl(ao_driver_t *this
 static int probe_audio_devices(oss_driver_t *this) {
   static const char *const base_names[2] = {"/dev/dsp", "/dev/sound/dsp"};
   int base_num, i;
-  int audio_fd, rate;
+  long audio_fd, rate;
   int best_rate;
   char devname[30];
 
@@ -701,9 +701,9 @@ static ao_driver_t *open_plugin (audio_d
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
