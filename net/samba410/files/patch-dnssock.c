--- lib/addns/dnssock.c.orig	2018-06-11 14:38:36 UTC
+++ lib/addns/dnssock.c
@@ -221,9 +221,7 @@ static DNS_ERROR dns_send_udp(struct dns
 	ssize_t ret;
 
 	do {
-		ret = sendto(conn->s, buf->data, buf->offset, 0,
-		     (struct sockaddr *)&conn->RecvAddr,
-		     sizeof(conn->RecvAddr));
+		ret = send(conn->s, buf->data, buf->offset, 0);
 	} while ((ret == -1) && (errno == EINTR));
 
 	if (ret != buf->offset) {
