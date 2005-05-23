--- kopete/protocols/msn/msnsocket.cpp	Wed Feb 23 05:30:54 2005
+++ kopete/protocols/msn/msnsocket.cpp	Sun May 22 13:33:31 2005
@@ -133,7 +133,7 @@
 
 void MSNSocket::slotSocketError( int error )
 {
-	kdWarning( 14140 ) << k_funcinfo << "Error: " << error << endl;
+	kdWarning( 14140 ) << k_funcinfo << "Error: " << error << " (" << m_socket->errorString() << ")" << endl;
 
 	if(!KSocketBase::isFatalError(error))
 		return;
@@ -467,7 +467,6 @@
 		kdDebug( 14141 ) << k_funcinfo << "Sending command: " << QString( *it ).stripWhiteSpace() << endl;
 		m_socket->writeBlock( *it, ( *it ).length() );
 		m_sendQueue.remove( it );
-		emit commandSent();
 
 		// If the queue is empty again stop waiting for readyWrite signals
 		// because of the CPU usage
