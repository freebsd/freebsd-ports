--- NServer-0.9.1/NServer.h.orig	Mon Aug  4 13:19:19 2003
+++ NServer-0.9.1/NServer.h	Mon Aug  4 13:19:52 2003
@@ -243,6 +243,7 @@
 	 RServer():NServer() {
 		_ServerList = NULL;
 		_CurrentServer = NULL;
+		_pServerStream = NULL;
 	} void init(MPList * serverlist);
 
 	/**
