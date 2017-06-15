--- util.c.orig	2016-10-07 14:32:44 UTC
+++ util.c
@@ -285,7 +285,7 @@ static int GetInterfaceIndex( const char
 
     close( i_fd );
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     return ifr.ifr_index;
 #else
     return ifr.ifr_ifindex;
@@ -451,7 +451,7 @@ static void RawFillHeaders(struct udpraw
                         uint8_t ttl, uint8_t tos, uint16_t len)
 {
 #ifndef __APPLE__
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     struct ip *iph = &(dgram->iph);
 #else
     struct iphdr *iph = &(dgram->iph);
@@ -468,7 +468,7 @@ static void RawFillHeaders(struct udpraw
     printf("Filling raw header (%p) (%s:%u -> %s:%u)\n", dgram, ipsrc_str, portsrc, ipdst_str, portdst);
 #endif
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     // Fill ip header
     iph->ip_hl    = 5;              // ip header with no specific option
     iph->ip_v     = 4;
@@ -710,7 +710,7 @@ int OpenSocket( const char *_psz_arg, in
                 i_raw_srcaddr, connect_addr.sin.sin_addr.s_addr, i_raw_srcport,
                 ntohs(connect_addr.sin.sin_port), i_ttl, i_tos, 0);
             i_fd = socket( AF_INET, SOCK_RAW, IPPROTO_RAW );
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
             if ( setsockopt( i_fd, IPPROTO_IP, IP_HDRINCL, &hincl, sizeof(hincl)) == -1 )
             {
                 msg_Err( NULL, "unable to set socket (%s)", strerror(errno) );
@@ -747,7 +747,7 @@ int OpenSocket( const char *_psz_arg, in
 
             if ( bind_addr.ss.ss_family != AF_UNSPEC )
             {
-                #if !defined(__APPLE__) && !defined(__FreeBSD__)
+                #if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__DragonFly__)
                 if ( IN6_IS_ADDR_MULTICAST( &bind_addr.sin6.sin6_addr ) )
                 {
                     struct ipv6_mreq imr;
@@ -827,7 +827,7 @@ normal_bind:
             }
             else
 #endif
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
             if ( i_bind_if_index )
             {
                 /* Linux-specific interface-bound multicast */
