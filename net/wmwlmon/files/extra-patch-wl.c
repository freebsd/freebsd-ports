--- ./wl.c.orig 2006-05-10 06:57:57.000000000 +0300
+++ ./wl.c      2008-05-10 11:03:57.000000000 +0300
@@ -283,6 +284,7 @@
 int
 get_wi_signal(const char *interface)
 {
+#if __FreeBSD__ > 600100 && __FreeBSD__ < 700052 /* wi support is broken on 7 because of struct wi_req removal*/
 	int		s;
 	struct ifreq	ifr;
 	struct wi_req	wreq;
@@ -319,6 +321,9 @@
 #ifdef __FreeBSD__
 	return (wreq.wi_val[1]);
 #endif
+#else
+	return -1;
+#endif
 }
 
 /*
