--- src/lib/packet.c.orig	2007-10-17 08:15:35.000000000 +0200
+++ src/lib/packet.c	2007-10-17 08:04:21.000000000 +0200
@@ -546,16 +546,16 @@ void
 packet_put_raw(PACKET *p, const void *_data, ssize_t size)
 {
 	ssize_t	 written;
-	void	*data;
+	char	*data;
 
 	if (p == NULL || _data == NULL || size <= 0)
 		return;
 
-	data = (void *) _data;
+	data = (char *) _data;
 	while (size) {
 		written = buf_put_raw(p->pkt_wbuf, data, size);
 		size -= written;
-		(char *) data += written;
+		data += written;
 		if (size)
 			_packet_write(p);
 	}
@@ -604,14 +604,16 @@ void
 packet_get_raw(PACKET *p, void *data, ssize_t size)
 {
 	ssize_t readed;
+	char	*cdata;
 
 	if (p == NULL || data == NULL || size <= 0)
 		return;
 
+	cdata = (char *)data;
 	while (size) {
-		readed = buf_get_raw(p->pkt_rbuf, data, size);
+		readed = buf_get_raw(p->pkt_rbuf, cdata, size);
 		size -= readed;
-		(char *) data += readed;
+		cdata += readed;
 		if (size)
 			_packet_read(p);
 	}
