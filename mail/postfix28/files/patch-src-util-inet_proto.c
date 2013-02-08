--- src/util/inet_proto.c.orig	2013-01-27 19:07:09.000000000 +0000
+++ src/util/inet_proto.c	2013-01-27 19:08:12.000000000 +0000
@@ -205,7 +205,7 @@
 	    pf->dns_atype_list = make_unsigned_vector(2, T_AAAA, 0);
 	    pf->sa_family_list = make_uchar_vector(2, AF_INET6, 0);
 	    break;
-	} else if (errno == EAFNOSUPPORT) {
+	} else if (errno == EAFNOSUPPORT || errno == EPROTONOSUPPORT) {
 	    msg_fatal("%s: IPv6 support is disabled: %m", context);
 	} else {
 	    msg_fatal("socket: %m");
@@ -219,7 +219,7 @@
 	    pf->dns_atype_list = make_unsigned_vector(3, T_A, T_AAAA, 0);
 	    pf->sa_family_list = make_uchar_vector(3, AF_INET, AF_INET6, 0);
 	    break;
-	} else if (errno == EAFNOSUPPORT) {
+	} else if (errno == EAFNOSUPPORT || errno == EPROTONOSUPPORT) {
 	    msg_warn("%s: IPv6 support is disabled: %m", context);
 	    msg_warn("%s: configuring for IPv4 support only", context);
 	    /* FALLTHROUGH */
