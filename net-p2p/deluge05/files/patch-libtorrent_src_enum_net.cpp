--- libtorrent/src/enum_net.cpp.orig	2008-02-29 13:02:02.000000000 -0600
+++ libtorrent/src/enum_net.cpp	2008-02-29 13:02:22.000000000 -0600
@@ -34,6 +34,7 @@
 
 #if defined TORRENT_BSD || defined TORRENT_LINUX
 #include <sys/ioctl.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <net/if.h>
 #elif defined TORRENT_WINDOWS
