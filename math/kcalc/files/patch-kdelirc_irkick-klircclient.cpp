--- kdelirc/irkick/klircclient.cpp.orig	Sat Sep 10 10:21:34 2005
+++ kdelirc/irkick/klircclient.cpp	Mon Jun  5 16:16:51 2006
@@ -55,15 +55,10 @@
 
 	sockaddr_un addr;
 	addr.sun_family = AF_UNIX;
-	strcpy(addr.sun_path, "/dev/lircd");
+	strcpy(addr.sun_path, "/var/run/lirc/lircd");
 	if(::connect(sock, (struct sockaddr *)(&addr), sizeof(addr)) == -1)
 	{	::close(sock);
-		// in case of mandrake...
-		strcpy(addr.sun_path, "/tmp/.lircd");
-		if(::connect(sock, (struct sockaddr *)(&addr), sizeof(addr)) == -1)
-		{	::close(sock);
-			return false;
-		}
+		return false;
 	}
 
 	theSocket = new QSocket;
