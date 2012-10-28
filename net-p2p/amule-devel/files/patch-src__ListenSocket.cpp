--- src/ListenSocket.cpp.orig	2012-05-11 20:38:58.000000000 +0200
+++ src/ListenSocket.cpp	2012-10-13 12:37:21.000000000 +0200
@@ -88,7 +88,9 @@
 
 void CListenSocket::OnAccept()
 {
-	m_pending = true;
+	// Backported from r10795
+	//m_pending = true;
+	m_pending = theApp->IsRunning();	// just do nothing if we are shutting down
 	// If the client is still at maxconnections,
 	// this will allow it to go above it ...
 	// But if you don't, you will get a lowID on all servers.
@@ -103,7 +105,8 @@
 				newclient->Safe_Delete();
 				m_pending = false;
 			} else {
-				wxASSERT(theApp->IsRunning());
+				// Backported from r10795
+				//wxASSERT(theApp->IsRunning());
 				if (!newclient->InitNetworkData()) {
 					// IP or port were not returned correctly
 					// from the accepted address, or filtered.
