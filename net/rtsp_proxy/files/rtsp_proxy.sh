--- rtsp_proxy.sh	Wed Dec 31 16:00:00 1969
+++ rtsp_proxy.sh	Tue Jun  8 22:54:49 1999
@@ -0,0 +1,2 @@
+#!/bin/sh
+[ -x /usr/local/sbin/rtsp_proxy ] && /usr/local/sbin/rtsp_proxy > /dev/null & && echo $! > /var/run/rtsp_proxy.pid && echo -n ' rtsp_proxy'
