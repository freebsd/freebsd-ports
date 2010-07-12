--- src/read_tcp.c.orig
+++ src/read_tcp.c
@@ -87,7 +87,7 @@ void print_read_tcp(struct text_object *obj, char *p, int p_max_size)
 	addr.sin_family = AF_INET;
 	addr.sin_port = rtd->port;
 	memcpy(&addr.sin_addr, he->h_addr, he->h_length);
-	if (!connect(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr))) {
+	if (connect(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr)) != 0) {
 		NORM_ERR("read_tcp: Couldn't create a connection");
 		return;
 	}
