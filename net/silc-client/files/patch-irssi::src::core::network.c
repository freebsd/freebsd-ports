--- irssi/src/core/network.c.orig	Sun Jan 25 10:11:14 2004
+++ irssi/src/core/network.c	Sun Jan 25 10:11:29 2004
@@ -611,7 +611,7 @@
 int net_hosterror_notfound(int error)
 {
 #ifdef HAVE_IPV6
-	return error != 1 && (error == EAI_NONAME || error == EAI_NODATA);
+	return error != 1 && (error == EAI_NONAME);
 #else
 	return error == HOST_NOT_FOUND || error == NO_ADDRESS;
 #endif
