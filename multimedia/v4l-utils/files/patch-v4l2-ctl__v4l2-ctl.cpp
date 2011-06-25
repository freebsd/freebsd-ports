--- v4l2-ctl/v4l2-ctl.cpp.orig	2011-06-01 13:23:03.000000000 +0200
+++ v4l2-ctl/v4l2-ctl.cpp	2011-06-04 10:03:21.000000000 +0200
@@ -21,7 +21,6 @@
  */
 
 #include <unistd.h>
-#include <features.h>		/* Uses _GNU_SOURCE to define getsubopt in stdlib.h */
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -36,7 +35,6 @@
 #include <sys/time.h>
 #include <dirent.h>
 #include <math.h>
-#include <sys/klog.h>
 
 #include <linux/videodev2.h>
 #include <libv4l2.h>
@@ -3279,6 +3277,7 @@
 		static char buf[40960];
 		int len;
 
+#ifndef __FreeBSD__
 		if (doioctl(fd, VIDIOC_LOG_STATUS, NULL) == 0) {
 			printf("\nStatus Log:\n\n");
 			len = klogctl(3, buf, sizeof(buf) - 1);
@@ -3300,6 +3299,7 @@
 				}
 			}
 		}
+#endif
 	}
 
 	/* List options */
