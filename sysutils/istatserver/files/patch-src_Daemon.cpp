--- src/Daemon.cpp.orig	2018-06-09 07:03:35 UTC
+++ src/Daemon.cpp
@@ -174,7 +174,7 @@ void Daemon::create(bool _back, const st
 	
 	length = offsetof(struct sockaddr_un, sun_path) + strlen(sockfile.c_str());
 	
-	if (bind(unix_socket, (struct sockaddr *) &local, length) == -1)
+	if (::bind(unix_socket, (struct sockaddr *) &local, length) == -1)
 	{
 		cout << "Could not bind UNIX socket: " << strerror(errno) << endl;
 		exit(1);
