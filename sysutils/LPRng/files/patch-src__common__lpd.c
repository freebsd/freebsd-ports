--- src/common/lpd.c.orig
+++ src/common/lpd.c
@@ -979,7 +979,6 @@
 * libwrap/tcp_wrappers:
 * draht@suse.de, Mon Jan 28 2002
 */
-		if( !unix_socket ){
 			struct request_info wrap_req;
 
 			request_init(&wrap_req, RQ_DAEMON, "lpd" , RQ_FILE, newsock, NULL);
@@ -993,7 +992,6 @@
 				close( newsock );
 				return;
 			}
-		}
 #endif
 
 		pid = Start_worker( "server", Service_connection, &args, newsock );
