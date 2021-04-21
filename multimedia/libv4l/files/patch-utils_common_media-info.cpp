--- utils/common/media-info.cpp.orig	2020-05-21 11:22:05 UTC
+++ utils/common/media-info.cpp
@@ -24,6 +24,10 @@
 #include <iostream>
 #include <fstream>
 #include <media-info.h>
+#ifndef __linux__
+#include <linux/videodev2.h>
+#include <fcntl.h>
+#endif
 
 static std::string num2s(unsigned num, bool is_hex = true)
 {
@@ -61,7 +65,7 @@ media_type mi_media_detect_type(const char *device)
 
 	if (stat(device, &sb) == -1)
 		return MEDIA_TYPE_CANT_STAT;
-
+#ifdef __linux__
 	std::string uevent_path("/sys/dev/char/");
 
 	uevent_path += num2s(major(sb.st_rdev), false) + ":" +
@@ -97,6 +101,23 @@ media_type mi_media_detect_type(const char *device)
 	}
 
 	uevent_file.close();
+#else // Not Linux
+	int fd = open(device, O_RDONLY);
+	if (fd >= 0) {
+		struct v4l2_capability caps;
+		int error = ioctl(fd, VIDIOC_QUERYCAP, &caps);
+		close(fd);
+		if (error == 0) {
+			if (caps.device_caps & V4L2_CAP_VIDEO_CAPTURE) {
+				return MEDIA_TYPE_VIDEO;
+			} else if (caps.device_caps & V4L2_CAP_VBI_CAPTURE) {
+				return MEDIA_TYPE_VBI;
+			} else if (caps.device_caps & V4L2_CAP_RADIO) {
+				return MEDIA_TYPE_RADIO;
+			}
+		}
+	}
+#endif
 	return MEDIA_TYPE_UNKNOWN;
 }
 
