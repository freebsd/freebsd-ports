This patch is necessary to allow compilation with clang over just GCC.

--- src/biblesync.cc.orig	2020-05-24 19:07:56 UTC
+++ src/biblesync.cc
@@ -253,7 +253,7 @@ string BibleSync::Setup()
 		server.sin_addr.s_addr = INADDR_ANY;
 
 		// make it receive-ready.
-		if (bind(server_fd, (struct sockaddr*)&server,
+		if (::bind(server_fd, (struct sockaddr*)&server,
 			 sizeof(server)) == -1)
 		{
 		    ok_so_far = false;
