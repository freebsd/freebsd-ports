--- src/rpc.c.orig	2009-01-02 15:22:29.000000000 +0100
+++ src/rpc.c	2010-06-29 14:24:39.000000000 +0200
@@ -68,7 +68,7 @@
 
 // Define the maximum amount of time (in seconds) to wait for a message
 #ifndef RPC_MESSAGE_TIMEOUT
-#define RPC_MESSAGE_TIMEOUT 30
+#define RPC_MESSAGE_TIMEOUT 10
 #endif
 
 // Define the maximum amount of time (in seconds) to wait for plugin connection
