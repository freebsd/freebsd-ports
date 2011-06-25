--- ./v4l2-ctl/ivtv-ctl.c.orig	2011-02-09 23:04:27.000000000 +0100
+++ ./v4l2-ctl/ivtv-ctl.c	2011-06-03 19:20:05.000000000 +0200
@@ -498,7 +498,13 @@
 			if (ioctl(fd, VIDEO_GET_EVENT, &ev) < 0) {
 				fprintf(stderr, "ioctl: VIDEO_GET_EVENT failed\n");
 				break;
-			} else if (ev.timestamp == 0) {
+			}
+#ifndef __FreeBSD__
+			else if (ev.timestamp == 0)
+#else
+			else if (ev.timestamp.tv_sec == 0)
+#endif
+			{
 				unsigned long long pts = 0, frame = 0;
 				struct timeval tv;
 				gettimeofday(&tv, NULL);
