--- libs/libmythtv/recorders/dvbdev/dvbci.cpp.orig	2010-04-26 23:30:52.000000000 +0200
+++ libs/libmythtv/recorders/dvbdev/dvbci.cpp	2014-01-22 09:13:22.000000000 -0500
@@ -28,7 +28,11 @@
 #include <errno.h>
 #include <ctype.h>
 #include <linux/dvb/ca.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#else
+#include <stdlib.h>
+#endif
 #include <netinet/in.h>
 #include <poll.h>
 #include <string.h>
