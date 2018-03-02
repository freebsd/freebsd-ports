--- libs/libmythupnp/mmulticastsocketdevice.h.orig	2015-06-16 16:03:30 UTC
+++ libs/libmythupnp/mmulticastsocketdevice.h
@@ -22,6 +22,7 @@
 #  include <ws2tcpip.h>
 # endif
 #else
+# include <sys/types.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 # include <netinet/ip.h>
