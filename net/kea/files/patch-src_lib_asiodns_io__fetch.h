--- src/lib/asiodns/io_fetch.h.orig	2025-08-20 08:14:44 UTC
+++ src/lib/asiodns/io_fetch.h
@@ -16,6 +16,7 @@
 #include <util/buffer.h>
 
 #include <boost/asio/coroutine.hpp>
+#include <boost/asio/deadline_timer.hpp>
 #include <boost/shared_array.hpp>
 #include <boost/shared_ptr.hpp>
 #include <boost/date_time/posix_time/posix_time_types.hpp>
