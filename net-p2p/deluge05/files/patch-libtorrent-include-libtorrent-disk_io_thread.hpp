--- libtorrent/include/libtorrent/disk_io_thread.hpp.orig	2008-07-23 00:04:51.000000000 +0400
+++ libtorrent/include/libtorrent/disk_io_thread.hpp	2009-03-21 17:06:18.000000000 +0300
@@ -41,6 +41,7 @@
 #include <boost/thread/thread.hpp>
 #include <boost/function.hpp>
 #include <boost/thread/mutex.hpp>
+#include <boost/thread/condition.hpp>
 #include <boost/bind.hpp>
 #include <boost/pool/pool.hpp>
 #include <boost/noncopyable.hpp>
