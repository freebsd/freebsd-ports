--- src/xplib/xp_lib.cc.orig	2005-07-27 08:38:16 UTC
+++ src/xplib/xp_lib.cc
@@ -82,7 +82,7 @@ int xp_lib::OpenUDPSocket(struct sockadd
 		return FAIL;
 	}
 	if (bind_sin != NULL)
-		if (bind(sock, (struct sockaddr *)bind_sin, sizeof(struct sockaddr_in)) == -1) {
+		if (::bind(sock, (struct sockaddr *)bind_sin, sizeof(struct sockaddr_in)) == -1) {
 			return FAIL;
 		}
 
