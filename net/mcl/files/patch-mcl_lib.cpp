--- src/alc/mcl_lib.cpp.orig	Tue Jul 22 19:37:39 2003
+++ src/alc/mcl_lib.cpp	Wed Oct 15 16:16:55 2003
@@ -1265,8 +1265,10 @@
 	if (id >= MCLCB_MAX_ID || (mclcb = mclcbs[id]) == NULL) {
 		TRACE((mcl_stdout, "   mcl_recvfrom: not an MCL id, switch to standard recvfrom\n"))
 		return (recvfrom(id, (char*)buf, len, 0, saddr,
-#ifdef LINUX
+#if defined(LINUX)
 				(size_t*) /* linux => uint, solaris => int */
+#elif defined(FREEBSD)
+				(socklen_t*) 
 #endif
 				saddr_len));
 	}
