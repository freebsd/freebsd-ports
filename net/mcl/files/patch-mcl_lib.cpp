--- src/alc/mcl_lib.cpp.orig	Wed Nov 26 15:38:14 2003
+++ src/alc/mcl_lib.cpp	Tue Dec 16 23:58:46 2003
@@ -1384,8 +1384,10 @@
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
@@ -1520,8 +1522,11 @@
 	if (id >= MCLCB_MAX_ID || (mclcb = mclcbs[id]) == NULL) {
 		TRACE((mcl_stdout, "   mcl_recvfrom: not an MCL id, switch to standard recvfrom\n"))
 		return (recvfrom(id, (char*)buf, len, 0, saddr,
-#ifdef LINUX
+#if defined(LINUX)
 				(size_t*) /* linux => uint, solaris => int */
+#elif defined(FREEBSD)
+				(socklen_t*)
+
 #endif
 				saddr_len));
 	}
