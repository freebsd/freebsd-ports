--- tvsim/tvsim_main.c.orig	Fri Jul 30 16:37:05 2004
+++ tvsim/tvsim_main.c	Fri Jul 30 17:00:10 2004
@@ -63,6 +63,9 @@
 #include "tvsim/tvsim_gui.h"
 #include "tvsim/tvsim_version.h"
 
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <machine/ioctl_bt848.h>
+#endif
 
 // prior to 8.4 there's a SEGV when evaluating const scripts (Tcl tries to modify the string)
 #if (TCL_MAJOR_VERSION > 8) || ((TCL_MAJOR_VERSION == 8) && (TCL_MINOR_VERSION >= 4))
@@ -493,7 +496,6 @@
    }
 
 #else // __NetBSD__ || __FreeBSD__
-   char * pDevName;
    ulong lfreq;
    uint  norm;
    bool result = FALSE;
@@ -505,26 +507,26 @@
    {
       if ( (*pIsTuner) && (lfreq != 0) )
       {
-         if (tuner_fd != -1)
+         if (video_fd != -1)
          {
             // mute audio
             int mute_arg = AUDIO_MUTE;
-            if (ioctl (tuner_fd, BT848_SAUDIO, &mute_arg) == 0)
+            if (ioctl (video_fd, BT848_SAUDIO, &mute_arg) == 0)
             {
                dprintf0("Muted tuner audio.\n");
             }
             else
-               fprintf(stderr, "muting audio (ioctl AUDIO_MUTE)\n", strerror(errno));
+               fprintf(stderr, "muting audio (ioctl AUDIO_MUTE): %s\n", strerror(errno));
 
             // Set the tuner frequency
-            if(ioctl(tuner_fd, VIDIOCSFREQ, &lfreq) == 0)
+            if(ioctl(video_fd, TVTUNER_SETFREQ, &lfreq) == 0)
             {
                dprintf1("Vbi-TuneChannel: set to %.2f\n", (double)freq/16);
 
                result = TRUE;
             }
             else
-               fprintf(stderr, "setting tuner frequency (ioctl VIDIOCSFREQ): \n", strerror(errno));
+               fprintf(stderr, "setting tuner frequency (ioctl TVTUNER_SETFREQ): %s\n", strerror(errno));
          }
       }
    }
