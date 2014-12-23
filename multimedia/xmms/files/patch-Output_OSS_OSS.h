--- Output/OSS/OSS.h.orig	2003-06-11 18:44:17 UTC
+++ Output/OSS/OSS.h
@@ -37,7 +37,19 @@
 #include <stdio.h>
 #include <string.h>
 
+#ifdef __FreeBSD__
+#include <sys/soundcard.h>
+#else
 #include "soundcard.h"
+#endif
+
+#ifndef SNDCTL_DSP_GETPLAYVOL
+#define SNDCTL_DSP_GETPLAYVOL	SOUND_MIXER_READ_PCM
+#endif
+
+#ifndef SNDCTL_DSP_SETPLAYVOL
+#define SNDCTL_DSP_SETPLAYVOL	SOUND_MIXER_WRITE_PCM
+#endif
 
 #include "xmms/plugin.h"
 #include "libxmms/configfile.h"
@@ -82,6 +94,8 @@ int oss_get_output_time(void);
 int oss_get_written_time(void);
 void oss_set_audio_params(void);
 
+int oss_get_fd(void);
+
 void oss_free_convert_buffer(void);
 int (*oss_get_convert_func(int output, int input))(void **, int);
 int (*oss_get_stereo_convert_func(int output, int input))(void **, int, int);
