--- src/main/listen.c	4 Sep 2007 15:25:11 -0000	1.100
+++ src/main/listen.c	25 Sep 2007 09:34:31 -0000	1.101
@@ -862,6 +862,34 @@
 		return -1;
 	}
 
+	{
+		struct sockaddr_storage	src;
+		socklen_t	        sizeof_src = sizeof(src);
+
+		memset(&src, 0, sizeof_src);
+		if (getsockname(this->fd, (struct sockaddr *) &src,
+				&sizeof_src) < 0) {
+			return -1;
+		}
+
+		if (src.ss_family == AF_INET) {
+			struct sockaddr_in	*s4;
+			
+			s4 = (struct sockaddr_in *)&src;
+			sock->ipaddr.ipaddr.ip4addr = s4->sin_addr;
+			
+#ifdef HAVE_STRUCT_SOCKADDR_IN6
+		} else if (src.ss_family == AF_INET6) {
+			struct sockaddr_in6	*s6;
+			
+			s6 = (struct sockaddr_in6 *)&src;
+			sock->ipaddr.ipaddr.ip6addr = s6->sin6_addr;
+#endif
+		} else {
+			return -1;
+		}
+	}
+
 #if 0
 #ifdef O_NONBLOCK
 	if ((flags = fcntl(this->fd, F_GETFL, NULL)) < 0)  {
