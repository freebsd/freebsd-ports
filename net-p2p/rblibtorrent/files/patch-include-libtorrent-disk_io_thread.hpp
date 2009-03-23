--- include/libtorrent/disk_io_thread.hpp.orig	2008-04-05 12:32:51.000000000 +0400
+++ include/libtorrent/disk_io_thread.hpp	2009-03-21 17:05:33.000000000 +0300
@@ -41,6 +41,7 @@
 #include <boost/thread/thread.hpp>
 #include <boost/function.hpp>
 #include <boost/thread/mutex.hpp>
+#include <boost/thread/condition.hpp>
 #include <boost/bind.hpp>
 #include <boost/pool/pool.hpp>
 #include <boost/noncopyable.hpp>
