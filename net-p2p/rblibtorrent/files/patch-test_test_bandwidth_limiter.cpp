--- test/test_bandwidth_limiter.cpp.orig	2009-11-24 16:09:08.000000000 +0300
+++ test/test_bandwidth_limiter.cpp	2009-11-24 16:09:28.000000000 +0300
@@ -8,6 +8,7 @@
 #include "libtorrent/time.hpp"
 #include "libtorrent/intrusive_ptr_base.hpp"
 
+#include <iostream>
 #include <boost/lexical_cast.hpp>
 
 struct torrent;
