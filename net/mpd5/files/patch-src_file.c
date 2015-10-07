--- src/iface.c	2015/05/13 12:31:43	1.223
+++ src/iface.c	2015/06/02 08:57:13	1.224
@@ -3654,9 +3654,11 @@
 	b->name, iface->ifname, ifname));
 
     if (ioctl(s, SIOCSIFNAME, (caddr_t)&ifr) < 0) {
-	Perror("[%s] IFACE: ioctl(%s, SIOCSIFNAME)", b->name, iface->ifname);
-	close(s);
-	return(-1);
+	if (errno != EEXIST) {
+	    Perror("[%s] IFACE: ioctl(%s, SIOCSIFNAME)", b->name, iface->ifname);
+	    close(s);
+	    return(-1);
+	}
     }
 
     close(s);
