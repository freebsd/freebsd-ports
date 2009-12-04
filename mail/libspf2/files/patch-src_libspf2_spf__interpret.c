--- src/libspf2/spf_interpret.c	2008-10-22 11:47:43.000000000 -0400
+++ src/libspf2/spf_interpret.c	2009-09-08 00:42:25.000000000 -0400
@@ -505,7 +505,7 @@
 	char		dst_ip6_buf[ INET6_ADDRSTRLEN ];
 
 	struct in6_addr		src_ipv6;
-	int				cidr, mask;
+	int				cidr, cidr_save, mask;
 	int				i;
 	int				match;
 
@@ -517,6 +517,7 @@
 	cidr = SPF_i_mech_cidr(spf_request, mech);
 	if ( cidr == 0 )
 		cidr = 128;
+	cidr_save = cidr;
 
 	match = TRUE;
 	for( i = 0; i < array_elem( ipv6.s6_addr ) && match; i++ )
@@ -538,7 +539,7 @@
 		INET_NTOP(AF_INET6, &ipv6.s6_addr,
 							dst_ip6_buf, sizeof(dst_ip6_buf));
 		SPF_debugf( "ip_match:  %s == %s  (/%d):  %d",
-				src_ip6_buf, dst_ip6_buf, cidr, match );
+				src_ip6_buf, dst_ip6_buf, cidr_save, match );
 	}
 
 	return match;

