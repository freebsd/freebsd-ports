--- v4l2-dbg/v4l2-dbg.cpp.orig	2011-06-01 13:23:03.000000000 +0200
+++ v4l2-dbg/v4l2-dbg.cpp	2011-06-04 10:04:30.000000000 +0200
@@ -17,7 +17,6 @@
  */
 
 #include <unistd.h>
-#include <features.h>		/* Uses _GNU_SOURCE to define getsubopt in stdlib.h */
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -31,7 +30,6 @@
 #include <sys/ioctl.h>
 #include <sys/time.h>
 #include <math.h>
-#include <sys/klog.h>
 
 #include <linux/videodev2.h>
 #include <media/v4l2-chip-ident.h>
@@ -767,6 +765,7 @@
 		static char buf[40960];
 		int len;
 
+#ifndef __FreeBSD__
 		if (doioctl(fd, VIDIOC_LOG_STATUS, NULL, "VIDIOC_LOG_STATUS") == 0) {
 			printf("\nStatus Log:\n\n");
 			len = klogctl(3, buf, sizeof(buf) - 1);
@@ -788,6 +787,7 @@
 				}
 			}
 		}
+#endif
 	}
 
 	if (options[OptListSymbols]) {
