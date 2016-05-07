Index: sync.c
--- sync.c.orig	2010-06-16 01:30:30 UTC
+++ sync.c
@@ -487,7 +487,11 @@ peer_connect(peer)	/* peer list is read-
 #ifdef AF_INET6
 		case AF_INET6:
 			SA6(res->ai_addr)->sin6_port = service;
-			laddrstr = "::";
+			if (conf.c_syncsrcaddr != NULL) {
+				laddrstr = conf.c_syncsrcaddr;
+			} else {
+				laddrstr = "::";
+			}
 			break;
 #endif
 		default:
