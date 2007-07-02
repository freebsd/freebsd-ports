--- speventcb.cpp.orig	Sun Jul  1 13:21:42 2007
+++ speventcb.cpp	Mon Jul  2 21:20:16 2007
@@ -15,6 +15,8 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netinet/tcp.h>
+#include <sys/uio.h>
+#include <unistd.h>
 
 #include "speventcb.hpp"
 #include "spsession.hpp"
@@ -27,7 +29,7 @@
 #include "sprequest.hpp"
 #include "spmsgblock.hpp"
 
-#include "config.h"
+//#include "config.h"
 #include "event_msgqueue.h"
 #include "event.h"
 
@@ -476,7 +478,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
