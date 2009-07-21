--- libtun6/diag.c.orig	2009-07-16 02:16:51.000000000 +0900
+++ libtun6/diag.c	2009-07-21 16:19:12.000000000 +0900
@@ -98,10 +98,10 @@
 			return -1;
 	}
 #else
+	const char tundev[] = "/dev/tun0";
 #if 1	/* BSD creates a tunnel even on stat() - skip diagnostics */
 	return 0;
 #else
-	const char tundev[] = "/dev/tun0";
 	struct stat st;
 
 	if (stat (tundev, &st) == 0)
