--- src/xfers.c.orig	Fri Mar 22 16:26:04 2002
+++ src/xfers.c	Tue Mar 26 17:39:53 2002
@@ -611,7 +611,9 @@
 				pthread_join(htxf->tid, &thread_retval);
 			}
 #ifdef USE_IPV6
-			freeaddrinfo(htxf->listen_addr);
+			if(htxf->listen_addr) {
+				freeaddrinfo(htxf->listen_addr);
+			}
 #endif
 			g_free(htxf);
 			if (nxfers > (i+1)) {
