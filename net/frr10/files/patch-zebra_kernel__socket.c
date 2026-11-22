--- zebra/kernel_socket.c.orig
+++ zebra/kernel_socket.c
@@ -1033,6 +1033,14 @@ void rtm_read(struct rt_msghdr *rtm)
 #endif
 #ifdef RTF_WASCLONED /*freebsd*/
 	if (flags & RTF_WASCLONED)
+		return;
+#endif
+#ifdef RTF_LLDATA /*freebsd*/
+	/*
+	 * Neighbor cache entries (e.g. IPv6 ND), not routes: as kernel
+	 * routes they would override static or BGP host routes.
+	 */
+	if (flags & RTF_LLDATA)
 		return;
 #endif
 
