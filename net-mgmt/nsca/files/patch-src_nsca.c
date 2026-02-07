--- src/nsca.c.orig	2017-04-20 16:25:28 UTC
+++ src/nsca.c
@@ -917,7 +917,7 @@ static void accept_connection(int sock, 
 				return;
 
 			/* try and handle temporary errors */
-			if(errno==EWOULDBLOCK || errno==EINTR || errno==ECHILD){
+			if(errno==EWOULDBLOCK || errno==EINTR || errno==ECHILD || errno==ECONNABORTED){
 				if(mode==MULTI_PROCESS_DAEMON)
 					sleep(1);
 				else
