--- libao2/ao_oss.c.orig	Sun Jul 27 13:41:36 2003
+++ libao2/ao_oss.c	Sun Jul 27 13:49:37 2003
@@ -247,7 +247,11 @@
 	mp_msg(MSGT_AO,MSGL_ERR,"\nFatal error: *** CANNOT RE-OPEN / RESET AUDIO DEVICE *** %s\n", strerror(errno));
 	return;
     }
-
+    
+#if defined(FD_CLOEXEC) && defined(F_SETFD)
+  fcntl(audio_fd, F_SETFD, FD_CLOEXEC);
+#endif
+  
   ioctl (audio_fd, SNDCTL_DSP_SETFMT, &ao_data.format);
   if(ao_data.format != AFMT_AC3) {
     if (ao_data.channels > 2)
