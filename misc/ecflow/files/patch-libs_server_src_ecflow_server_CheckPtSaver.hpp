--- libs/server/src/ecflow/server/CheckPtSaver.hpp.orig	2024-11-11 09:34:56 UTC
+++ libs/server/src/ecflow/server/CheckPtSaver.hpp
@@ -12,6 +12,7 @@
 #define ecflow_server_CheckPtSaver_HPP
 
 #include <boost/asio.hpp>
+#include <boost/asio/deadline_timer.hpp>
 
 #include "ecflow/core/Filesystem.hpp"
 
