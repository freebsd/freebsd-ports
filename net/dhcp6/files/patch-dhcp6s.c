--- dhcp6s.c.orig	2018-09-02 19:43:29 UTC
+++ dhcp6s.c
@@ -527,7 +527,7 @@ server6_init()
 		    strerror(errno));
 		exit(1);
 	}
-#if !defined(__linux__) && !defined(__sun__)
+#if !defined(__linux__) && !defined(__sun__) && !defined(__FreeBSD__)
 	/* make the socket write-only */
 	if (shutdown(outsock, 0)) {
 		d_printf(LOG_ERR, FNAME, "shutdown(outbound, 0): %s",
