--- spserver/speventcb.cpp.orig	2008-10-23 22:08:00.000000000 +0800
+++ spserver/speventcb.cpp	2009-07-02 11:44:48.000000000 +0800
@@ -177,14 +177,16 @@
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
 					SP_EventHelper::doError( session );
 				} else {
-					addEvent( session, EV_READ, -1 );
+					//addEvent( session, EV_READ, -1 );
 					sp_syslog( LOG_NOTICE, "session(%d.%d) busy, process session error later",
 							sid.mKey, sid.mSeq );
 				}
@@ -196,7 +198,7 @@
 		if( 0 == session->getRunning() ) {
 			SP_EventHelper::doTimeout( session );
 		} else {
-			addEvent( session, EV_READ, -1 );
+			//addEvent( session, EV_READ, -1 );
 			sp_syslog( LOG_NOTICE, "session(%d.%d) busy, process session timeout later",
 					sid.mKey, sid.mSeq );
 		}
@@ -230,7 +232,7 @@
 								sid.mKey, sid.mSeq, errno, session->getStatus(), session->getOutList()->getCount() );
 						SP_EventHelper::doError( session );
 					} else {
-						addEvent( session, EV_WRITE, -1 );
+						//addEvent( session, EV_WRITE, -1 );
 						sp_syslog( LOG_NOTICE, "session(%d.%d) busy, process session error later, errno [%d]",
 								sid.mKey, sid.mSeq, errno );
 					}
@@ -244,10 +246,10 @@
 			if( SP_Session::eExit == session->getStatus() ) {
 				ret = -1;
 				if( 0 == session->getRunning() ) {
-					sp_syslog( LOG_NOTICE, "session(%d.%d) normal exit", sid.mKey, sid.mSeq );
+					sp_syslog( LOG_WARNING, "session(%d.%d) normal exit", sid.mKey, sid.mSeq );
 					SP_EventHelper::doClose( session );
 				} else {
-					addEvent( session, EV_WRITE, -1 );
+					//addEvent( session, EV_WRITE, -1 );
 					sp_syslog( LOG_NOTICE, "session(%d.%d) busy, terminate session later",
 							sid.mKey, sid.mSeq );
 				}
@@ -269,7 +271,7 @@
 		if( 0 == session->getRunning() ) {
 			SP_EventHelper::doTimeout( session );
 		} else {
-			addEvent( session, EV_WRITE, -1 );
+			//addEvent( session, EV_WRITE, -1 );
 			sp_syslog( LOG_NOTICE, "session(%d.%d) busy, process session timeout later",
 					sid.mKey, sid.mSeq );
 		}
@@ -409,7 +411,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		sp_syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
@@ -473,7 +475,7 @@
 	sp_syslog( LOG_WARNING, "session(%d.%d) error, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
 			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
 
 	// onResponse will ignore this session, so it's safe to destroy session here
@@ -524,8 +526,8 @@
 	sp_syslog( LOG_WARNING, "session(%d.%d) timeout, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
-			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			eventArg->getSessionManager()->getCount(), (int)eventArg->getSessionManager()->getFreeCount() );
 
 	// onResponse will ignore this session, so it's safe to destroy session here
 	session->getHandler()->close();
@@ -553,10 +555,10 @@
 	SP_EventArg * eventArg = (SP_EventArg*)session->getArg();
 	SP_Sid_t sid = session->getSid();
 
-	sp_syslog( LOG_NOTICE, "session(%d.%d) close, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
+	sp_syslog( LOG_WARNING, "session(%d.%d) close, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
 			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
 
 	session->getHandler()->close();
