--- source3/utils/smbfilter.c.orig	2026-01-20 15:42:54 UTC
+++ source3/utils/smbfilter.c
@@ -291,7 +291,7 @@ static void start_filter(char *desthost)
 		exit(1);
 	}
 
-	if (listen(s, 5) == -1) {
+	if (listen(s, DEFAULT_LISTEN_BACKLOG) == -1) {
 		d_printf("listen failed\n");
 	}
 
