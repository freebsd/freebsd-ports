--- wl.c.orig	2008-05-12 21:42:17.000000000 -0700
+++ wl.c	2008-05-15 21:27:36.000000000 -0700
@@ -283,6 +283,7 @@
 int
 get_wi_signal(const char *interface)
 {
+#if __FreeBSD__ > 600100 && __FreeBSD__ < 700052 /* wi support is broken on 7 because of struct wi_req removal*/
 	int		s;
 	struct ifreq	ifr;
 	struct wi_req	wreq;
@@ -319,6 +320,9 @@
 #ifdef __FreeBSD__
 	return (wreq.wi_val[1]);
 #endif
+#else
+	return (-1);
+#endif
 }
 
 /*
