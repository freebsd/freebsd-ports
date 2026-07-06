--- src/lib/asiolink/interval_timer.h.orig	2026-06-22 07:49:20 UTC
+++ src/lib/asiolink/interval_timer.h
@@ -16,6 +16,7 @@
 #pragma GCC diagnostic pop
 #endif
 
+#include <boost/asio/deadline_timer.hpp>
 #include <boost/shared_ptr.hpp>
 #include <functional>
 
