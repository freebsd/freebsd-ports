--- boreas/ping.c	2021-04-15 09:22:56.000000000 -0500
+++ boreas/ping.c	2021-06-14 19:24:32.398090000 -0500
@@ -26,9 +26,13 @@
 #include <errno.h>
 #include <glib.h>
 #include <ifaddrs.h> /* for getifaddrs() */
+#if defined __linux__
 #include <linux/sockios.h>
+#endif
 #include <netinet/icmp6.h>
+#include <sys/types.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/ip6.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/tcp.h>
@@ -36,7 +40,6 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #undef G_LOG_DOMAIN
@@ -105,7 +108,11 @@
   int cur_so_sendbuf = -1;
 
   /* Get the current size of the output queue size */
+#ifdef __FreeBSD__
+  if (ioctl (soc, TIOCOUTQ, &cur_so_sendbuf) == -1)
+#else
   if (ioctl (soc, SIOCOUTQ, &cur_so_sendbuf) == -1)
+#endif
     {
       g_warning ("%s: ioctl error: %s", __func__, strerror (errno));
       usleep (100000);
@@ -121,7 +128,11 @@
       while (cur_so_sendbuf >= so_sndbuf)
         {
           usleep (100000);
+#ifdef __FreeBSD__
+          if (ioctl (soc, TIOCOUTQ, &cur_so_sendbuf) == -1)
+#else
           if (ioctl (soc, SIOCOUTQ, &cur_so_sendbuf) == -1)
+#endif
             {
               g_warning ("%s: ioctl error: %s", __func__, strerror (errno));
               usleep (100000);
@@ -208,12 +219,23 @@
   static int init = -1;
 
   icmp = (struct icmphdr *) sendbuf;
+#ifdef __FreeBSD__
+  icmp->icmp_type = ICMP_ECHO;
+  icmp->icmp_code = 0;
+#else
   icmp->type = ICMP_ECHO;
   icmp->code = 0;
+#endif
 
+
   len = 8 + datalen;
+#ifdef __FreeBSD__
+  icmp->icmp_cksum = 0;
+  icmp->icmp_cksum = in_cksum ((u_short *) icmp, len);
+#else
   icmp->checksum = 0;
   icmp->checksum = in_cksum ((u_short *) icmp, len);
+#endif
 
   memset (&soca, 0, sizeof (soca));
   soca.sin_family = AF_INET;
@@ -276,7 +298,11 @@
     }
   else
     {
+#ifdef __FreeBSD__
+      dst4.s_addr = dst6_p->s6_addr[12];
+#else
       dst4.s_addr = dst6_p->s6_addr32[3];
+#endif
       send_icmp_v4 (scanner->icmpv4soc, dst4_p);
     }
 }
@@ -538,7 +564,11 @@
     }
   else
     {
+#ifdef __FreeBSD__
+      dst4.s_addr = dst6_p->s6_addr[12];
+#else
       dst4.s_addr = dst6_p->s6_addr32[3];
+#endif
       send_tcp_v4 (scanner, dst4_p);
     }
 }
@@ -588,7 +618,7 @@
       /* Need to transform the IPv6 mapped IPv4 address back to an IPv4 string.
        * We can not just use the host_value_str as it might be an IPv4 mapped
        * IPv6 string. */
-      if (inet_ntop (AF_INET, &(dst6_p->s6_addr32[3]), ipv4_str,
+      if (inet_ntop (AF_INET, &(dst6_p->s6_addr[12]), ipv4_str,
                      sizeof (ipv4_str))
           == NULL)
         {
