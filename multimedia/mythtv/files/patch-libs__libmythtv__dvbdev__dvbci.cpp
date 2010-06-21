--- libs/libmythtv/dvbdev/dvbci.cpp.orig	2010-03-07 04:11:52.000000000 +0100
+++ libs/libmythtv/dvbdev/dvbci.cpp	2010-04-26 23:30:52.000000000 +0200
@@ -28,7 +28,9 @@
 #include <errno.h>
 #include <ctype.h>
 #include <linux/dvb/ca.h>
+#ifndef __FreeBSD__
 #include <malloc.h>
+#endif
 #include <netinet/in.h>
 #include <poll.h>
 #include <string.h>
