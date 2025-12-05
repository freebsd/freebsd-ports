--- libs/base/src/ecflow/base/SslClient.hpp.orig	2024-11-11 09:34:56 UTC
+++ libs/base/src/ecflow/base/SslClient.hpp
@@ -19,6 +19,8 @@
 /// not the Client project
 ///
 
+#include <boost/asio/deadline_timer.hpp>
+
 #include "ecflow/base/ClientToServerRequest.hpp"
 #include "ecflow/base/ServerToClientResponse.hpp"
 #include "ecflow/base/ssl_connection.hpp"
