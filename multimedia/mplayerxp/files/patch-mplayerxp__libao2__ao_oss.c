--- mplayerxp/libao2/ao_oss.c.orig	Sat Jul  2 18:59:01 2005
+++ mplayerxp/libao2/ao_oss.c	Sun Oct  1 22:06:55 2006
@@ -171,6 +171,7 @@
   }
   show_fmts();
   rval=0;
+#ifndef __FreeBSD__
   if (ioctl (audio_fd, SNDCTL_DSP_GETCAPS, &rval) != -1)
   {
 	MSG_INFO("AO-INFO: Capabilities: ");
@@ -185,6 +186,7 @@
 	if(rval & DSP_CAP_BIND) MSG_INFO("bind ");
 	MSG_INFO("\n");	
   }
+#endif
   close(audio_fd);
 }
 // open & setup audio device
