--- src/alc/mcl_network.cpp.orig	Tue Jul 22 19:37:39 2003
+++ src/alc/mcl_network.cpp	Tue Oct 14 15:47:45 2003
@@ -414,8 +414,10 @@
 				pkt->pkt_len = recvfrom(mg->ses_sock,
 					pkt->get_buf(), pkt->get_buf_len(),
 					0, &saddr,
-#ifdef LINUX
+#if defined(LINUX)
 					(size_t*)
+#elif defined(FREEBSD)
+					(socklen_t*)
 #endif
 					&saddr_len);
 #ifdef WIN32
@@ -483,8 +485,10 @@
 			pkt->pkt_len = recvfrom(mg->priv_sock,
 					pkt->get_buf(), pkt->get_buf_len(),
 					0, &saddr,
-#ifdef LINUX
+#if defined(LINUX)
 					(size_t*)
+#elif defined(FREEBSD)
+					(socklen_t*)
 #endif
 					&saddr_len);
 #ifdef WIN32
@@ -663,8 +667,10 @@
 		err = setsockopt(fd, SOL_SOCKET, buf, (char*)&val, sizeof(val));
 	else
 		err = getsockopt(fd, SOL_SOCKET, buf, (char*)&val,
-#ifdef LINUX
-				(size_t*) /* linux => uint, solaris => int */
+#if defined(LINUX)
+					(size_t*)
+#elif defined(FREEBSD)
+					(socklen_t*)
 #endif
 				&len);
 	if (err < 0) {
@@ -938,7 +944,7 @@
 
 		if (mcl_is_valid_sock(mg->priv_sock) &&
 		    getsockname(mg->priv_sock, (struct sockaddr *)&tmp_addr,
-#ifdef LINUX
+#if defined(LINUX) || defined(FREEBSD)
 				(socklen_t*)
 #endif
 				&tmp_len) < 0) {
