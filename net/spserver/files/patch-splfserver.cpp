--- splfserver.cpp.orig	Mon Jul  2 21:20:29 2007
+++ splfserver.cpp	Mon Jul  2 21:20:36 2007
@@ -17,7 +17,7 @@
 #include "spexecutor.hpp"
 #include "sputils.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_LFServer :: SP_LFServer( const char * bindIP, int port, SP_HandlerFactory * handlerFactory )
