--- protocols/fddi/nd_fddi.h.orig	Sat Oct 12 00:25:59 2002
+++ protocols/fddi/nd_fddi.h	Sat Oct 12 00:26:10 2002
@@ -26,7 +26,7 @@
 #ifndef __nd_fddi_h
 #define __nd_fddi_h
 
-#include <netinet/if_fddi.h>
+#include <net/fddi.h>
 
 #include <netdude/nd_gettext.h>
 #include <netdude/nd_packet.h>
