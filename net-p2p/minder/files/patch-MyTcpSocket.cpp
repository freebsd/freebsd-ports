--- MyTcpSocket.cpp.orig	Sun Jan 16 01:07:56 2005
+++ MyTcpSocket.cpp	Sun Jan 16 01:09:39 2005
@@ -85,7 +85,7 @@
 
 	// we ignore whatever ip the minion sends us
 	// we only use the ip from the connection endpoint
-	ipaddr_t ip2 = GetRemoteIP();
+	ipaddr_t ip2 = GetRemoteIP4();
 DEB(	printf("Incoming: id '%s' %s:%d cmd '%s'\n",id.c_str(),GetRemoteAddress().c_str(),port,cmd.c_str());)
 	if (cmd == "Goodbye")
 	{
