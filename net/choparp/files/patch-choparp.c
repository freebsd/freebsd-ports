--- choparp.c.orig	Fri Feb 13 20:27:14 2004
+++ choparp.c	Fri Feb 13 20:27:51 2004
@@ -437,6 +437,9 @@
 #endif
     if ((fd = openbpf(ifname, &buf, &buflen)) < 0)
 	return(-1);
+	#ifndef DEBUG
+    		daemon(0, 0);
+	#endif
     loop(fd, buf, buflen);
     return(-1);
 }
