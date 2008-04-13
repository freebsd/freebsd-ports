--- pf_key_v2.c.orig	2004-12-08 04:07:00.000000000 +0800
+++ pf_key_v2.c	2008-04-13 21:00:05.000000000 +0800
@@ -2204,13 +2204,13 @@
 		goto cleanup;
 	addr->sadb_address_exttype = SADB_EXT_ADDRESS_SRC;
 	addr->sadb_address_len = len / PF_KEY_V2_CHUNK;
-#ifdef LINUX_IPSEC
+#if defined(LINUX_IPSEC) || defined (__FreeBSD__) 
 	addr->sadb_address_proto = tproto;
 #else
 	addr->sadb_address_proto = IPSEC_ULPROTO_ANY;
 #endif
 	addr->sadb_address_reserved = 0;
-#ifdef LINUX_IPSEC
+#if defined(LINUX_IPSEC) || defined (__FreeBSD__) 
 	pf_key_v2_setup_sockaddr(addr + 1, laddr, 0, sport, 0);
 #else
 	pf_key_v2_setup_sockaddr(addr + 1, laddr, 0, IPSEC_PORT_ANY, 0);
@@ -2238,13 +2238,13 @@
 		goto cleanup;
 	addr->sadb_address_exttype = SADB_EXT_ADDRESS_DST;
 	addr->sadb_address_len = len / PF_KEY_V2_CHUNK;
-#ifdef LINUX_IPSEC
+#if defined(LINUX_IPSEC) || defined (__FreeBSD__) 
 	addr->sadb_address_proto = tproto;
 #else
 	addr->sadb_address_proto = IPSEC_ULPROTO_ANY;
 #endif
 	addr->sadb_address_reserved = 0;
-#ifdef LINUX_IPSEC
+#if defined(LINUX_IPSEC) || defined (__FreeBSD__) 
 	pf_key_v2_setup_sockaddr(addr + 1, raddr, 0, dport, 0);
 #else
 	pf_key_v2_setup_sockaddr(addr + 1, raddr, 0, IPSEC_PORT_ANY, 0);
