--- util/gnutv/gnutv.c.orig	2014-03-21 19:26:36 UTC
+++ util/gnutv/gnutv.c
@@ -28,6 +28,7 @@
 #include <signal.h>
 #include <pthread.h>
 #include <sys/poll.h>
+#include <sys/socket.h>
 #include <libdvbapi/dvbdemux.h>
 #include <libdvbapi/dvbaudio.h>
 #include <libdvbsec/dvbsec_cfg.h>
