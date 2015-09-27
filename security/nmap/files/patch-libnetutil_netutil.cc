--- libnetutil/netutil.cc.orig	2015-09-21 19:57:10 UTC
+++ libnetutil/netutil.cc
@@ -3604,7 +3604,7 @@ int send_ip_packet_sd(int sd, const stru
      must deal with it here rather than when building the packet,
      because they should be in NBO when I'm sending over raw
      ethernet */
-#if (defined(FREEBSD) && (__FreeBSD_version < 1000022)) || BSDI || NETBSD || DEC || MACOSX
+#if (defined(FREEBSD) && (__FreeBSD_version < 1100030)) || BSDI || NETBSD || DEC || MACOSX
   ip->ip_len = ntohs(ip->ip_len);
   ip->ip_off = ntohs(ip->ip_off);
 #endif
@@ -3614,7 +3614,7 @@ int send_ip_packet_sd(int sd, const stru
                (int) sizeof(struct sockaddr_in));
 
   /* Undo the byte order switching. */
-#if (defined(FREEBSD) && (__FreeBSD_version < 1000022)) || BSDI || NETBSD || DEC || MACOSX
+#if (defined(FREEBSD) && (__FreeBSD_version < 1100030)) || BSDI || NETBSD || DEC || MACOSX
   ip->ip_len = htons(ip->ip_len);
   ip->ip_off = htons(ip->ip_off);
 #endif
