- backport patch for OBS Studio Virtual Camera on FreeBSD
- see https://www.davidschlachter.com/misc/freebsd-obs-virtualcam

diff --git plugins/linux-v4l2/v4l2-output.c b/plugins/linux-v4l2/v4l2-output.c
index 05ac70b42f0..0ddd3152384 100644
--- plugins/linux-v4l2/v4l2-output.c
+++ plugins/linux-v4l2/v4l2-output.c
@@ -27,6 +27,7 @@ static void virtualcam_destroy(void *data)
 	bfree(data);
 }
 
+#ifdef __linux__
 static bool is_flatpak_sandbox(void)
 {
 	static bool flatpak_info_exists = false;
@@ -98,6 +99,32 @@ static int loopback_module_load()
 	return run_command(
 		"pkexec modprobe v4l2loopback exclusive_caps=1 card_label='OBS Virtual Camera' && sleep 0.5");
 }
+#else
+bool loopback_module_available()
+{
+	struct v4l2_capability capability;
+	char new_device[16];
+	int fd;
+	int i;
+
+	for (i = 0; i != MAX_DEVICES; i++) {
+		snprintf(new_device, 16, "/dev/video%d", i);
+		fd = open(new_device, O_RDWR);
+		if (fd < 0)
+			continue;
+		if (ioctl(fd, VIDIOC_QUERYCAP, &capability) < 0) {
+			close(fd);
+			continue;
+		}
+		if (capability.capabilities & V4L2_CAP_VIDEO_OUTPUT) {
+			close(fd);
+			return true;
+		}
+		close(fd);
+	}
+	return false;
+}
+#endif
 
 static void *virtualcam_create(obs_data_t *settings, obs_output_t *output)
 {
@@ -131,13 +158,19 @@ static bool try_connect(void *data, int device)
 	if (vcam->device < 0)
 		return false;
 
-	if (ioctl(vcam->device, VIDIOC_QUERYCAP, &capability) < 0)
+	if (ioctl(vcam->device, VIDIOC_QUERYCAP, &capability) < 0) {
+		close(vcam->device);
+		vcam->device = -1;
 		return false;
+	}
 
 	format.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
 
-	if (ioctl(vcam->device, VIDIOC_G_FMT, &format) < 0)
+	if (ioctl(vcam->device, VIDIOC_G_FMT, &format) < 0) {
+		close(vcam->device);
+		vcam->device = -1;
 		return false;
+	}
 
 	struct obs_video_info ovi;
 	obs_get_video_info(&ovi);
@@ -149,16 +182,22 @@ static bool try_connect(void *data, int device)
 	parm.parm.output.timeperframe.numerator = ovi.fps_den;
 	parm.parm.output.timeperframe.denominator = ovi.fps_num;
 
-	if (ioctl(vcam->device, VIDIOC_S_PARM, &parm) < 0)
+	if (ioctl(vcam->device, VIDIOC_S_PARM, &parm) < 0) {
+		close(vcam->device);
+		vcam->device = -1;
 		return false;
+	}
 
 	format.fmt.pix.width = width;
 	format.fmt.pix.height = height;
 	format.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
 	format.fmt.pix.sizeimage = vcam->frame_size;
 
-	if (ioctl(vcam->device, VIDIOC_S_FMT, &format) < 0)
+	if (ioctl(vcam->device, VIDIOC_S_FMT, &format) < 0) {
+		close(vcam->device);
+		vcam->device = -1;
 		return false;
+	}
 
 	struct video_scale_info vsi = {0};
 	vsi.format = VIDEO_FORMAT_YUY2;
@@ -176,11 +215,12 @@ static bool virtualcam_start(void *data)
 {
 	struct virtualcam_data *vcam = (struct virtualcam_data *)data;
 
+#ifdef __linux__
 	if (!loopback_module_loaded()) {
 		if (loopback_module_load() != 0)
 			return false;
 	}
-
+#endif
 	for (int i = 0; i < MAX_DEVICES; i++) {
 		if (!try_connect(vcam, i))
 			continue;
