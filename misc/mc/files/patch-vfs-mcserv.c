--- vfs/mcserv.c.orig	Sun Dec  8 07:12:30 2002
+++ vfs/mcserv.c	Tue Jun 15 03:15:09 2004
@@ -582,7 +582,7 @@
     int n;
 
     rpc_get (msock, RPC_STRING, &file, RPC_END);
-    n = readlink (file, buffer, 2048);
+    n = readlink (file, buffer, 2048 - 1);
     send_status (n, errno);
     if (n >= 0) {
 	buffer[n] = 0;
