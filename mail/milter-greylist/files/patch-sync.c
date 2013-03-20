Index: sync.c
diff -u -p sync.c.orig sync.c
--- sync.c.orig	2010-04-17 12:19:02.000000000 +0900
+++ sync.c	2013-03-14 14:57:39.284674283 +0900
@@ -478,7 +478,11 @@ peer_connect(peer)	/* peer list is read-
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
