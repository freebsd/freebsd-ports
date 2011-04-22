--- src/libs/zbxcomms/comms.c.orig	2011-04-15 14:17:29.000000000 -0500
+++ src/libs/zbxcomms/comms.c	2011-04-22 09:47:38.403907930 -0500
@@ -756,19 +756,14 @@
 						ip ? ip : "-", port, zbx_sock_last_error(), strerror_from_system(zbx_sock_last_error()));
 			}
 
-#if defined(IPV6_V6ONLY)
-#ifdef _WINDOWS
+#if defined(IPPROTO_IPV6) && defined(IPV6_V6ONLY)
 			if (PF_INET6 == current_ai->ai_family &&
 				ZBX_TCP_ERROR == setsockopt(s->sockets[s->num_socks], IPPROTO_IPV6, IPV6_V6ONLY, (void *)&on, sizeof(on)))
-#else
-			if (PF_INET6 == current_ai->ai_family &&
-				ZBX_TCP_ERROR == setsockopt(s->sockets[s->num_socks], SOL_IPV6, IPV6_V6ONLY, (void *)&on, sizeof(on)))
-#endif
 			{
 				zbx_set_tcp_strerror("setsockopt() with IPV6_V6ONLY for [[%s]:%s] failed with error %d: %s",
 						ip ? ip : "-", port, zbx_sock_last_error(), strerror_from_system(zbx_sock_last_error()));
 			}
-#endif	/* IPV6_V6ONLY */
+#endif
 
 			if (ZBX_TCP_ERROR == bind(s->sockets[s->num_socks], current_ai->ai_addr, current_ai->ai_addrlen))
 			{
