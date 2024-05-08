--- boreas/ping.c	2024-04-22 03:55:15.000000000 -0500
+++ boreas/ping.c	2024-04-24 02:34:16.020861000 -0500
@@ -13,9 +13,13 @@
 #include <errno.h>
 #include <glib.h>
 #include <ifaddrs.h> /* for getifaddrs() */
+#if defined __linux__
 #include <linux/sockios.h>
+#endif
+#include <sys/types.h>
 #include <netinet/icmp6.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/ip6.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/tcp.h>
@@ -23,7 +27,6 @@
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/time.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #undef G_LOG_DOMAIN
@@ -102,7 +105,11 @@
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
@@ -118,7 +125,11 @@
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
@@ -198,21 +209,38 @@
 
   int len;
   int datalen = 56;
+#ifdef __FreeBSD__
+  struct icmp *icmp;
+#else
   struct icmphdr *icmp;
+#endif
 
   /* Throttling related variables */
   static int so_sndbuf = -1; // socket send buffer
   static int init = -1;
 
+#ifdef __FreeBSD__
+  icmp = (struct icmp *) sendbuf;
+  icmp->icmp_type = ICMP_ECHO;
+  icmp->icmp_code = 0;
+  icmp->icmp_id = get_echo_id ();
+  icmp->icmp_seq = 0x0100;
+#else
   icmp = (struct icmphdr *) sendbuf;
   icmp->type = ICMP_ECHO;
   icmp->code = 0;
   icmp->un.echo.id = get_echo_id ();
   icmp->un.echo.sequence = 0x0100;
+#endif
 
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
@@ -285,7 +313,11 @@
         }
       else
         {
+#ifdef __FreeBSD__
+          dst4.s_addr = dst6_p->s6_addr[12];
+#else
           dst4.s_addr = dst6_p->s6_addr32[3];
+#endif
           send_icmp_v4 (scanner->icmpv4soc, dst4_p);
         }
       if (grace_period > 0)
@@ -550,7 +582,11 @@
     }
   else
     {
-      dst4.s_addr = dst6_p->s6_addr32[3];
+#ifdef __FreeBSD__
+       dst4.s_addr = dst6_p->s6_addr[12];
+#else
+       dst4.s_addr = dst6_p->s6_addr32[3];
+#endif
       send_tcp_v4 (scanner, dst4_p);
     }
 }
@@ -600,7 +636,11 @@
       /* Need to transform the IPv6 mapped IPv4 address back to an IPv4 string.
        * We can not just use the host_value_str as it might be an IPv4 mapped
        * IPv6 string. */
+#if defined(__FreeBSD__)
+      if (inet_ntop (AF_INET, &(dst6_p->s6_addr[12]), ipv4_str,
+#else
       if (inet_ntop (AF_INET, &(dst6_p->s6_addr32[3]), ipv4_str,
+#endif
                      sizeof (ipv4_str))
           == NULL)
         {
