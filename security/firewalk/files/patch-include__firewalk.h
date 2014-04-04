--- include/firewalk.h.orig	Wed Sep 14 19:19:27 2005
+++ include/firewalk.h	Wed Sep 14 19:20:37 2005
@@ -41,6 +41,10 @@
 #include <dnet.h>
 #include <libnet.h>
 
+#ifndef BIOCIMMEDIATE
+#define BIOCIMMEDIATE	_IOW('B',112,u_int)
+#endif
+
 #define FW_BANNER  "Firewalk (c) 2002 Mike D. Schiffman \
 <mike@infonexus.com>\nhttp://www.packetfactory.net/firewalk\n\
 for more information.\n"
