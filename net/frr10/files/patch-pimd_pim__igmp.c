Zero the sockaddr before binding the IGMP socket.

pim_igmp_sock_add() binds its raw IGMP socket with a struct sockaddr_in it never
zeroes, so sin_zero carries whatever was on the stack.  Linux looks at sin_addr
alone and the garbage is harmless there.  FreeBSD resolves the address in
rip_bind() with ifa_ifwithaddr_fib_check(), which compares every sa_len byte
through sa_equal() -- sin_zero included -- so the lookup misses a perfectly
local address and bind() fails with EADDRNOTAVAIL.  pimd is then left without an
IGMP socket on any interface.

Submitted upstream: https://github.com/FRRouting/frr/pull/23455

--- pimd/pim_igmp.c.orig	2026-09-24 18:59:47 UTC
+++ pimd/pim_igmp.c	2026-09-24 18:59:47 UTC
@@ -1271,6 +1271,7 @@ struct gm_sock *pim_igmp_sock_add(struct list *igmp_sock_list,
 		return NULL;
 	}
 
+	memset(&sin, 0, sizeof(sin));
 	sin.sin_family = AF_INET;
 	sin.sin_addr = ifaddr;
 	sin.sin_port = 0;
