--- libs/server/src/ecflow/server/PeriodicScheduler.hpp.orig	2024-11-11 09:34:56 UTC
+++ libs/server/src/ecflow/server/PeriodicScheduler.hpp
@@ -15,6 +15,7 @@
 
 #include <boost/asio.hpp>
 #include <boost/asio/bind_executor.hpp>
+#include <boost/asio/deadline_timer.hpp>
 
 #include "ecflow/core/Chrono.hpp"
 
