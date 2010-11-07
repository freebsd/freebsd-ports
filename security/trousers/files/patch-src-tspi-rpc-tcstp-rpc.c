--- src/tspi/rpc/tcstp/rpc.c.orig	2010-03-12 05:26:51.000000000 +0900
+++ src/tspi/rpc/tcstp/rpc.c	2010-10-24 21:04:04.846552639 +0900
@@ -306,7 +306,7 @@
 		errno = 0;
 		if ((recv_size = recv(sock, buffer+recv_total, size-recv_total, 0)) <= 0) {
 			if (recv_size < 0) {
-				if (errno == EINTR)
+				if (errno == EINTR || errno == EAGAIN)
 					continue;
 				LogError("Socket receive connection error: %s.", strerror(errno));
 			} else {
