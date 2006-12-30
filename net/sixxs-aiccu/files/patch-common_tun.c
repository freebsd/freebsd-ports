--- common/tun.c.orig	Tue Jul 25 02:20:46 2006
+++ common/tun.c	Thu Nov 30 02:02:05 2006
@@ -703,9 +703,7 @@
 
 	char		buf[128];
 	unsigned int	i;
-#ifndef _FREEBSD
 	int		mode = IFF_MULTICAST | IFF_POINTOPOINT;
-#endif
 
 	/* Try the configured interface */
 	tun_log(LOG_DEBUG, "start", "Trying Configured TUN/TAP interface %s...\n", g_aiccu->ipv6_interface);
@@ -752,7 +750,7 @@
 #endif
 #endif
 
-#ifdef _DFBSD
+#ifdef NEED_IFHEAD
 	tun_log(LOG_DEBUG, "start", "Setting TUNSIFHEAD for %s\n", g_aiccu->ipv6_interface);
 	mode = 1;
 	if (ioctl(tun_fd, TUNSIFHEAD, &mode, sizeof(mode)) == -1)
