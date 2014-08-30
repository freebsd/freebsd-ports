--- modules/log-prelude/log-prelude.cpp.orig
+++ modules/log-prelude/log-prelude.cpp
@@ -27,7 +27,11 @@
 
  /* $Id: log-prelude.cpp 1278 2007-05-29 16:04:00Z yoann $ */
 
+#include <cstdlib>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include "log-prelude.hpp"
 #include "Nepenthes.hpp"
 #include "LogManager.hpp"
