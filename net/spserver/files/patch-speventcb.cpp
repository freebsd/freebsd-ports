--- speventcb.cpp.orig	Mon Jun 18 12:41:11 2007
+++ speventcb.cpp	Mon Jun 18 12:42:31 2007
@@ -14,6 +14,8 @@
 #include <stdlib.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <sys/uio.h>
+#include <unistd.h>
 
 #include "speventcb.hpp"
 #include "spsession.hpp"
@@ -26,7 +28,7 @@
 #include "sprequest.hpp"
 #include "spmsgblock.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 #include "event.h"
 
@@ -341,7 +343,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
