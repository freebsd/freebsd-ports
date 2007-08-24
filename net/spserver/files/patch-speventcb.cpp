--- spserver/speventcb.cpp.orig	Wed Aug 22 22:04:05 2007
+++ spserver/speventcb.cpp	Thu Aug 23 07:33:14 2007
@@ -26,7 +26,7 @@
 #include "spiochannel.hpp"
 #include "spioutils.hpp"
 
-#include "config.h"   // from libevent, for event.h
+//#include "config.h"   // from libevent, for event.h
 #include "event_msgqueue.h"
 #include "event.h"
 
@@ -396,7 +396,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
