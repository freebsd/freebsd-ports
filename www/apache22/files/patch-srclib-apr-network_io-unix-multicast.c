--- srclib/apr/network_io/unix/multicast.c.orig	2007-08-05 00:58:21.000000000 +0300
+++ srclib/apr/network_io/unix/multicast.c	2007-08-05 00:59:51.000000000 +0300
@@ -57,11 +57,10 @@
     }
 }
 
-#if APR_HAVE_IPV6
 static unsigned int find_if_index(const apr_sockaddr_t *iface)
 {
     unsigned int index = 0;
-#ifdef HAVE_GETIFADDRS
+#if defined(HAVE_GETIFADDRS) && APR_HAVE_IPV6
     struct ifaddrs *ifp, *ifs;
 
     /**
@@ -92,6 +91,7 @@
     return index;
 }
 
+#if APR_HAVE_IPV6
 static void fill_mip_v6(struct ipv6_mreq *mip, const apr_sockaddr_t *mcast,
                         const apr_sockaddr_t *iface)
 {
