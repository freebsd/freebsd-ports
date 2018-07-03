--- src/DashFileServer.cxx.orig	2018-07-02 11:55:29 UTC
+++ src/DashFileServer.cxx
@@ -218,8 +218,8 @@ int InitalizeNetwork ( int ArgPort, int 
 	memset(&(ListenAddr.sin_zero), '\0', 8);
 
 	// Bind the socket to the listening network struct.
-	if ( bind( NetworkSocket, (struct sockaddr *)&ListenAddr, 
-					sizeof( struct sockaddr ) ) == -1 )
+	if ( ::bind( NetworkSocket, (struct sockaddr *)&ListenAddr, 
+					sizeof( struct sockaddr ) ) == -1)
 	{
 		perror("InitalizeNetwork -- bind()");
 		return -1;
