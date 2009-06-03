--- spserver/speventcb.cpp.orig	2008-10-23 22:08:00.000000000 +0800
+++ spserver/speventcb.cpp	2009-06-03 10:20:01.000000000 +0800
@@ -177,8 +177,10 @@
 			addEvent( session, EV_READ, -1 );
 		} else {
 			int saved = errno;
-			sp_syslog( LOG_NOTICE, "session(%d.%d) read error, errno %d, status %d",
-					sid.mKey, sid.mSeq, errno, session->getStatus() );
+            if( 0 != errno ) {
+			    sp_syslog( LOG_WARNING, "session(%d.%d) read error, errno %d, status %d",
+				    	sid.mKey, sid.mSeq, errno, session->getStatus() );
+            }
 
 			if( EAGAIN != saved ) {
 				if( 0 == session->getRunning() ) {
@@ -244,7 +246,7 @@
 			if( SP_Session::eExit == session->getStatus() ) {
 				ret = -1;
 				if( 0 == session->getRunning() ) {
-					sp_syslog( LOG_NOTICE, "session(%d.%d) normal exit", sid.mKey, sid.mSeq );
+					sp_syslog( LOG_WARNING, "session(%d.%d) normal exit", sid.mKey, sid.mSeq );
 					SP_EventHelper::doClose( session );
 				} else {
 					addEvent( session, EV_WRITE, -1 );
@@ -409,7 +411,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		sp_syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
@@ -553,7 +555,7 @@
 	SP_EventArg * eventArg = (SP_EventArg*)session->getArg();
 	SP_Sid_t sid = session->getSid();
 
-	sp_syslog( LOG_NOTICE, "session(%d.%d) close, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
+	sp_syslog( LOG_WARNING, "session(%d.%d) close, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
 			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
