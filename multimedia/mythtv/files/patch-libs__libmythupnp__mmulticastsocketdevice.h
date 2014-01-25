--- libs/libmythupnp/mmulticastsocketdevice.h.orig	2013-09-18 16:06:08.000000000 -0400
+++ libs/libmythupnp/mmulticastsocketdevice.h	2014-01-22 08:24:26.000000000 -0500
@@ -18,6 +18,7 @@
 #  include <ws2tcpip.h>
 # endif
 #else
+# include <sys/types.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 # include <netinet/ip.h>

