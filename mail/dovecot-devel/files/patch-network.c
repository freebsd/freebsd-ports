--- src/lib/network.c.orig	Sun Jun 22 23:09:48 2003
+++ src/lib/network.c	Sun Jan 25 20:22:17 2004
@@ -591,7 +591,11 @@
 int net_hosterror_notfound(int error)
 {
 #ifdef HAVE_IPV6
+#ifdef EAI_NODATA
 	return error != 1 && (error == EAI_NONAME || error == EAI_NODATA);
+#else
+	return error != 1 && (error == EAI_NONAME);
+#endif
 #else
 	return error == HOST_NOT_FOUND || error == NO_ADDRESS;
 #endif
