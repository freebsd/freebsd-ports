--- spserver/speventcb.cpp.orig	2008-05-16 09:41:38.000000000 +0800
+++ spserver/speventcb.cpp	2008-05-16 09:41:59.000000000 +0800
@@ -394,7 +394,7 @@
 		char buffer[ 16 ] = { 0 };
 		session->getInBuffer()->take( buffer, sizeof( buffer ) );
 		sp_syslog( LOG_WARNING, "session(%d.%d) status is %d, ignore [%s...] (%dB)",
-			sid.mKey, sid.mSeq, session->getStatus(), buffer, session->getInBuffer()->getSize() );
+			sid.mKey, sid.mSeq, session->getStatus(), buffer, (int)session->getInBuffer()->getSize() );
 		session->getInBuffer()->reset();
 	}
 }
