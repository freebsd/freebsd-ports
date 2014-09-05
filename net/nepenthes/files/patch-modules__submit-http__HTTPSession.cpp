--- modules/submit-http/HTTPSession.cpp.orig
+++ modules/submit-http/HTTPSession.cpp
@@ -31,6 +31,10 @@
 #include <curl/types.h> /* new for v7 */
 #include <curl/easy.h> /* new for v7 */
 #include <sstream>
+#include <cstring>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <arpa/inet.h>
 #include <netinet/in.h>
 
 #include "HTTPSession.hpp"
