--- Output/OSS/audio.c.orig	2005-05-15 00:01:20 UTC
+++ Output/OSS/audio.c
@@ -23,7 +23,7 @@
 
 #define NFRAGS		32
 
-static gint fd = 0;
+static gint fd = -1;
 static char *buffer;
 static gboolean going, prebuffer, paused, unpause, do_pause, remove_prebuffer;
 static gint device_buffer_used, buffer_size, prebuffer_size, blk_size;
@@ -273,8 +273,10 @@ static void oss_write_audio(gpointer dat
 	{
 		output_time_offset += (output_bytes * 1000) / output.bps;
 		output_bytes = 0;
+#ifndef __FreeBSD__
 		close(fd);
 		fd = open(device_name,O_WRONLY);
+#endif
 		oss_setup_format(new_format, new_frequency, new_channels);
 	}
 	if (effects_enabled() && ep && ep->mod_samples)
@@ -480,6 +482,7 @@ void oss_close(void)
 	{
 		ioctl(fd, SNDCTL_DSP_RESET, 0);
 		close(fd);
+		fd = -1;
 	}
 	g_free(device_name);
 	oss_free_convert_buffer();
@@ -498,8 +501,10 @@ void oss_flush(gint time)
 	else
 	{
 		ioctl(fd, SNDCTL_DSP_RESET, 0);
+#ifndef __FreeBSD__
 		close(fd);
 		fd = open(device_name, O_WRONLY);
+#endif
 		oss_set_audio_params();
 		output_time_offset = time;
 		written = ((guint64)time * input.bps) / 1000;
@@ -568,8 +573,10 @@ void *oss_loop(void *arg)
 		else if (unpause && paused)
 		{
 			unpause = FALSE;
+#ifndef __FreeBSD__
 			close(fd);
 			fd = open(device_name, O_WRONLY);
+#endif
 			oss_set_audio_params();
 			paused = FALSE;
 		}
@@ -583,8 +590,10 @@ void *oss_loop(void *arg)
 			 */
 
 			ioctl(fd, SNDCTL_DSP_RESET, 0);
+#ifndef __FreeBSD__
 			close(fd);
 			fd = open(device_name, O_WRONLY);
+#endif
 			oss_set_audio_params();
 			output_time_offset = flush;
 			written = ((guint64)flush * input.bps) / 1000;
@@ -597,6 +606,7 @@ void *oss_loop(void *arg)
 
 	ioctl(fd, SNDCTL_DSP_RESET, 0);
 	close(fd);
+	fd = -1;
 	g_free(buffer);
 	pthread_exit(NULL);
 }
@@ -707,3 +717,8 @@ gint oss_open(AFormat fmt, gint rate, gi
 		pthread_create(&buffer_thread, NULL, oss_loop, NULL);
 	return 1;
 }
+
+int oss_get_fd(void)
+{
+	return fd;
+}
