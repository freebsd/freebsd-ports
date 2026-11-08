--- source3/libsmb/unexpected.c.orig	2026-01-20 15:42:54 UTC
+++ source3/libsmb/unexpected.c
@@ -90,7 +90,7 @@ NTSTATUS nb_packet_server_create(TALLOC_CTX *mem_ctx,
 		status = map_nt_error_from_unix(errno);
 		goto fail;
 	}
-	rc = listen(result->listen_sock, 5);
+	rc = listen(result->listen_sock, DEFAULT_LISTEN_BACKLOG);
 	if (rc < 0) {
 		status = map_nt_error_from_unix(errno);
 		goto fail;
