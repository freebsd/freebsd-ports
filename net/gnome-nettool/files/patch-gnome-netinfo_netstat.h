--- gnome-netinfo/netstat.h.orig	Sun Jul 20 22:31:57 2003
+++ gnome-netinfo/netstat.h	Sun Dec  7 01:32:10 2003
@@ -28,6 +28,11 @@
 #   define NETSTAT_PROTOCOL_FORMAT "%s %d %d %s %s %s %s %s" 
 #   define NETSTAT_ROUTE_FORMAT "%s %s %s %s %d %d %d %s" 
 #   define NETSTAT_MULTICAST_FORMAT "%s %d %s" 
+#elif defined(__FreeBSD__)
+#   define NETSTAT_PROTOCOL_FORMAT "%s %d %d %d.%d.%d.%d.%s %s %s"
+#   define ALT_NETSTAT_PROTOCOL_FORMAT "%s %d %d *.%s %s %s"
+#   define NETSTAT_ROUTE_FORMAT "%s %s %s %d %d %s"
+#   define NETSTAT_MULTICAST_FORMAT "%s %d %s"
 
 #endif
 
