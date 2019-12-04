--- src/lib-master/master-service.c.orig	2019-12-04 09:31:27 UTC
+++ src/lib-master/master-service.c
@@ -368,7 +368,7 @@ master_service_init(const char *name, enum master_serv
 	if ((flags & MASTER_SERVICE_FLAG_DONT_SEND_STATS) == 0) {
 		/* Initialize stats-client early so it can see all events. */
 		value = getenv(DOVECOT_STATS_WRITER_SOCKET_PATH);
-		if (value != NULL)
+		if (value != NULL && *value != '\0')
 			service->stats_client = stats_client_init(value, FALSE);
 	}
 
