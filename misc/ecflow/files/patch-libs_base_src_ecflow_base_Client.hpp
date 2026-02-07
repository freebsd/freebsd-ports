--- libs/base/src/ecflow/base/Client.hpp.orig	2024-11-11 09:34:56 UTC
+++ libs/base/src/ecflow/base/Client.hpp
@@ -12,6 +12,7 @@
 #define ecflow_base_Client_HPP
 
 #include <boost/asio.hpp>
+#include <boost/asio/deadline_timer.hpp>
 
 #include "ecflow/base/ClientToServerRequest.hpp"
 #include "ecflow/base/Connection.hpp"
