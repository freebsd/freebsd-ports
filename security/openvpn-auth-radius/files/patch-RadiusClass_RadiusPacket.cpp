--- RadiusClass/RadiusPacket.cpp.orig	2010-01-31 14:34:02 UTC
+++ RadiusClass/RadiusPacket.cpp
@@ -442,7 +442,7 @@ int RadiusPacket::radiusSend(list<Radius
     cliAddr.sin_port=htons(0);
  	 	
 	//Bind the socket port,
-    if(bind(socket2Radius,(struct sockaddr*)&cliAddr,sizeof(struct sockaddr))<0)
+    if(::bind(socket2Radius,(struct sockaddr*)&cliAddr,sizeof(struct sockaddr))<0)
 	{
 		cerr << "Cannot bind port: " << strerror(errno) << "\n";
 		socket2Radius=-1;
