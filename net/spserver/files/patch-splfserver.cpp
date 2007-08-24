--- spserver/splfserver.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/splfserver.cpp	Thu Aug 23 07:33:35 2007
@@ -18,7 +18,7 @@
 #include "sputils.hpp"
 #include "spioutils.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 
 SP_LFServer :: SP_LFServer( const char * bindIP, int port, SP_HandlerFactory * handlerFactory )
