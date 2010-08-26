diff -u -r srcold/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c src/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c
--- srcold/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c	2010-03-19 17:56:54.000000000 +0200
+++ src/libcharon/plugins/kernel_pfkey/kernel_pfkey_ipsec.c	2010-05-28 15:58:12.000000000 +0200
@@ -600,17 +600,43 @@
 }
 
 /**
- * add a host behind a sadb_address extension
+ * Copy a host_t as sockaddr_t to the given memory location. Ports are
+ * reset to zero as per RFC 2367.
+ * @returns		the number of bytes copied
  */
-static void host2ext(host_t *host, struct sadb_address *ext)
+static size_t hostcpy(void *dest, host_t *host)
 {
-	sockaddr_t *host_addr = host->get_sockaddr(host);
+	sockaddr_t *addr = host->get_sockaddr(host), *dest_addr = dest;
 	socklen_t *len = host->get_sockaddr_len(host);
+	memcpy(dest, addr, *len);
 #ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
-	host_addr->sa_len = *len;
+	dest_addr->sa_len = *len;
 #endif
-	memcpy((char*)(ext + 1), host_addr, *len);
-	ext->sadb_address_len = PFKEY_LEN(sizeof(*ext) + *len);
+	switch (dest_addr->sa_family)
+	{
+		case AF_INET:
+		{
+			struct sockaddr_in *sin = dest;
+			sin->sin_port = 0;
+			break;
+		}
+		case AF_INET6:
+		{
+			struct sockaddr_in6 *sin6 = dest;
+			sin6->sin6_port = 0;
+			break;
+		}
+	}
+	return *len;
+}
+
+/**
+ * add a host behind an sadb_address extension
+ */
+static void host2ext(host_t *host, struct sadb_address *ext)
+{
+	size_t len = hostcpy(ext + 1, host);
+	ext->sadb_address_len = PFKEY_LEN(sizeof(*ext) + len);
 }
 
 /**
@@ -1019,6 +1045,7 @@
 }
 #endif /*SADB_X_MIGRATE*/
 
+#ifndef __FreeBSD__
 #ifdef HAVE_NATT
 /**
  * Process a SADB_X_NAT_T_NEW_MAPPING message from the kernel
@@ -1076,6 +1103,7 @@
 	}
 }
 #endif /*HAVE_NATT*/
+#endif /*__FreeBSD__*/
 
 /**
  * Receives events from kernel
@@ -1137,11 +1165,13 @@
 			process_migrate(this, msg);
 			break;
 #endif /*SADB_X_MIGRATE*/
+#ifndef __FreeBSD__
 #ifdef HAVE_NATT
 		case SADB_X_NAT_T_NEW_MAPPING:
 			process_mapping(this, msg);
 			break;
 #endif /*HAVE_NATT*/
+#endif /*__FreeBSD__*/
 		default:
 			break;
 	}
@@ -1679,14 +1709,10 @@
 	req->sadb_x_ipsecrequest_level = IPSEC_LEVEL_UNIQUE;
 	if (mode == MODE_TUNNEL)
 	{
-		sockaddr_t *sa;
-		socklen_t sl;
-		sa = src->get_sockaddr(src);
-		sl = *src->get_sockaddr_len(src);
-		memcpy(req + 1, sa, sl);
-		sa = dst->get_sockaddr(dst);
-		memcpy((u_int8_t*)(req + 1) + sl, sa, sl);
-		req->sadb_x_ipsecrequest_len += sl * 2;
+		len = hostcpy(req + 1, src);
+		req->sadb_x_ipsecrequest_len += len;
+		len = hostcpy((char*)(req + 1) + len, dst);
+		req->sadb_x_ipsecrequest_len += len;
 	}
 
 	pol->sadb_x_policy_len += PFKEY_LEN(req->sadb_x_ipsecrequest_len);
