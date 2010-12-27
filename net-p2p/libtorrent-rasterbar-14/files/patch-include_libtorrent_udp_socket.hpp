--- include/libtorrent/udp_socket.hpp.orig	2010-12-10 20:38:45.000000000 +0300
+++ include/libtorrent/udp_socket.hpp	2010-12-10 20:39:05.000000000 +0300
@@ -37,6 +37,7 @@
 #include "libtorrent/session_settings.hpp"
 #include "libtorrent/buffer.hpp"
 
+#include <list>
 #include <vector>
 #include <boost/function.hpp>
 #include <boost/thread/mutex.hpp>
