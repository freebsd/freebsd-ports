--- libs/server/src/ecflow/server/NodeTreeTraverser.hpp.orig	2024-11-11 09:34:56 UTC
+++ libs/server/src/ecflow/server/NodeTreeTraverser.hpp
@@ -11,6 +11,8 @@
 #ifndef ecflow_server_NodeTreeTraverser_HPP
 #define ecflow_server_NodeTreeTraverser_HPP
 
+#include <boost/asio/deadline_timer.hpp>
+
 ///
 /// \brief This class will traverse the node tree periodically, It is tied to a server.
 /// This implementation uses a strand to ensure sequential processing of the node dependency traversal
