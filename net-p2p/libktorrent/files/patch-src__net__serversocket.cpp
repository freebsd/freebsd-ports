commit 881ef5274f281f52eab974a72e6c9a3c74157ead
Author: Joris Guisson <joris.guisson@gmail.com>
Date:   Thu Jan 3 18:51:13 2013 +0100

    Fix bug causing UDP connections not to get established on FreeBSD because FIONREAD returns the size of the data and the peer address
    
    REVIEW: 108076

diff --git a/src/net/serversocket.cpp b/src/net/serversocket.cpp
index 5d39433..399b4b1 100644
--- ./src/net/serversocket.cpp
+++ ./src/net/serversocket.cpp
@@ -133,9 +133,10 @@ namespace net
 		{
 			// The first packet may be 0 bytes in size
 			Buffer::Ptr buf = d->pool->get(ba < 1500 ? 1500 : ba);
-			if (d->sock->recvFrom(buf->get(), ba, addr) == (int)ba && ba > 0)
+			int bytes_read = d->sock->recvFrom(buf->get(), ba, addr);
+			if (bytes_read <= (int)ba && ba > 0)
 			{
-				buf->setSize(ba);
+                buf->setSize(bytes_read);
 				d->dhandler->dataReceived(buf, addr);
 			}
 			first = false;
@@ -154,7 +155,6 @@ namespace net
 			d->rsn->setEnabled(on);
 	}
 
-	
 	void ServerSocket::readyToWrite(int)
 	{
 		d->dhandler->readyToWrite(this);
@@ -186,6 +186,5 @@ namespace net
 			return false;
 	}
 
-
 }
 
