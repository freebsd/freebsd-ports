--- spserver/speventcb.cpp.orig	2009-12-13 10:02:38.000000000 +0800
+++ spserver/speventcb.cpp	2009-12-14 14:11:18.000000000 +0800
@@ -422,7 +422,7 @@ void SP_EventHelper :: doWork( SP_Sessio
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		sp_syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
@@ -486,7 +486,7 @@ void SP_EventHelper :: error( void * arg
 	sp_syslog( LOG_WARNING, "session(%d.%d) error, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
 			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
 
 	// onResponse will ignore this session, so it's safe to destroy session here
@@ -537,8 +537,8 @@ void SP_EventHelper :: timeout( void * a
 	sp_syslog( LOG_WARNING, "session(%d.%d) timeout, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
-			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			eventArg->getSessionManager()->getCount(), (int)eventArg->getSessionManager()->getFreeCount() );
 
 	// onResponse will ignore this session, so it's safe to destroy session here
 	session->getHandler()->close();
@@ -569,7 +569,7 @@ void SP_EventHelper :: myclose( void * a
 	sp_syslog( LOG_DEBUG, "session(%d.%d) close, r %d(%d), w %d(%d), i %d, o %d, s %d(%d)",
 			sid.mKey, sid.mSeq, session->getTotalRead(), session->getReading(),
 			session->getTotalWrite(), session->getWriting(),
-			session->getInBuffer()->getSize(), session->getOutList()->getCount(),
+			(int)session->getInBuffer()->getSize(), session->getOutList()->getCount(),
 			eventArg->getSessionManager()->getCount(), eventArg->getSessionManager()->getFreeCount() );
 
 	session->getHandler()->close();
