--- src/lib/howl/Posix/posix_interface.c.orig	Sun Oct 17 19:30:04 2004
+++ src/lib/howl/Posix/posix_interface.c	Sun Oct 17 19:31:47 2004
@@ -400,17 +400,19 @@
 	/* ip address */
 	sw_ipv4_address_init_from_saddr(&(nif->m_super.m_ipv4_address), ((struct sockaddr_in *) &ifr->ifr_addr)->sin_addr.s_addr);
 
-#if defined(__linux__)
 	/* get a socket for ioctling */
 	err = sw_posix_inet_socket(&sock);
 	sw_check_okay(err, exit);
 
+#if defined(SIOCGIFHWADDR)
 	/* mac address */
 	res = ioctl(sock, SIOCGIFHWADDR, ifr);
 	err = sw_translate_error(res == 0, errno);
 	sw_check_okay_log(err, exit);
 	sw_memcpy(nif->m_super.m_mac_address.m_id, (sw_uint8*)(ifr->ifr_hwaddr.sa_data), sizeof(sw_mac_address)); 
+#endif
 
+#if defined(SIOCGIFFLAGS)
 	/* ifnet flags */
 	res = ioctl(sock, SIOCGIFFLAGS, ifr);
 	err = sw_translate_error(res == 0, errno);
