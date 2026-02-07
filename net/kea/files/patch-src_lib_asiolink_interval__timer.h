--- src/lib/asiolink/interval_timer.h.orig	2025-08-20 08:14:44 UTC
+++ src/lib/asiolink/interval_timer.h
@@ -7,6 +7,7 @@
 #ifndef ASIOLINK_INTERVAL_TIMER_H
 #define ASIOLINK_INTERVAL_TIMER_H 1
 
+#include <boost/asio/deadline_timer.hpp>
 #include <boost/shared_ptr.hpp>
 #include <functional>
 
