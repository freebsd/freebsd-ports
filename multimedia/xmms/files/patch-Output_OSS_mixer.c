--- Output/OSS/mixer.c.orig	2001-06-16 13:30:35 UTC
+++ Output/OSS/mixer.c
@@ -34,12 +34,20 @@ static char* get_mixer_device(void)
 
 void oss_get_volume(int *l, int *r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs, dspfd;
+	long cmd;
 	gchar *devname;
 
-	devname = get_mixer_device();
-	fd = open(devname, O_RDONLY);
-	g_free(devname);
+	dspfd = oss_get_fd();
+	if (oss_cfg.use_master == 0 && dspfd != -1) {
+		fd = dspfd;
+		dspfd = 1;
+	} else {
+		devname = get_mixer_device();
+		fd = open(devname, O_RDONLY);
+		g_free(devname);
+		dspfd = 0;
+	}
 
 	/*
 	 * We dont show any errors if this fails, as this is called
@@ -49,28 +57,40 @@ void oss_get_volume(int *l, int *r)
 	{
 		ioctl(fd, SOUND_MIXER_READ_DEVMASK, &devs);
 		if ((devs & SOUND_MASK_PCM) && (oss_cfg.use_master==0))
-			cmd = SOUND_MIXER_READ_PCM;
+			cmd = (dspfd != 0) ? SNDCTL_DSP_GETPLAYVOL :
+			    SOUND_MIXER_READ_PCM;
 		else if ((devs & SOUND_MASK_VOLUME) && (oss_cfg.use_master==1))
 			cmd = SOUND_MIXER_READ_VOLUME;
 		else
 		{
-			close(fd);
+			if (dspfd == 0)
+				close(fd);
 			return;
 		}
 		ioctl(fd, cmd, &v);
 		*r = (v & 0xFF00) >> 8;
 		*l = (v & 0x00FF);
-		close(fd);
+		if (dspfd == 0)
+			close(fd);
 	}
 }
 
 void oss_set_volume(int l, int r)
 {
-	int fd, v, cmd, devs;
+	int fd, v, devs, dspfd;
+	long cmd;
 	gchar *devname;
 
-	devname = get_mixer_device();
-	fd = open(devname, O_RDONLY);
+	dspfd = oss_get_fd();
+	if (oss_cfg.use_master == 0 && dspfd != -1) {
+		fd = dspfd;
+		dspfd = 1;
+		devname = g_strdup("<OSS FD>");
+	} else {
+		devname = get_mixer_device();
+		fd = open(devname, O_RDONLY);
+		dspfd = 0;
+	}
 
 	if (fd != -1)
 	{
@@ -81,12 +101,14 @@ void oss_set_volume(int l, int r)
 			cmd = SOUND_MIXER_WRITE_VOLUME;
 		else
 		{
-			close(fd);
+			if (dspfd == 0)
+				close(fd);
 			return;
 		}
 		v = (r << 8) | l;
 		ioctl(fd, cmd, &v);
-		close(fd);
+		if (dspfd == 0)
+			close(fd);
 	}
 	else
 		g_warning("oss_set_volume(): Failed to open mixer device (%s): %s",
