--- src/modules/module-snapcast-discover.c.orig	2024-07-12 07:24:23 UTC
+++ src/modules/module-snapcast-discover.c
@@ -690,7 +690,11 @@ static void resolver_cb(AvahiServiceResolver *r, Avahi
 	spa_zero(ifreq);
 	fd = socket(family, SOCK_STREAM | SOCK_CLOEXEC | SOCK_NONBLOCK, 0);
 	ifreq.ifr_ifindex = interface;
+#ifndef __FreeBSD__
 	ioctl(fd, SIOCGIFNAME, &ifreq, sizeof(ifreq));
+#else
+	if_indextoname(interface, ifreq.ifr_name);
+#endif
 	pw_properties_setf(props, "snapcast.ifname", "%s", ifreq.ifr_name);
 	pw_properties_setf(props, "local.ifname", "%s", ifreq.ifr_name);
 
