--- zebra/zapi_msg.c.orig	2026-05-31 06:08:07 UTC
+++ zebra/zapi_msg.c
@@ -309,10 +309,13 @@ int zsend_interface_address(int cmd, struct zserv *cli
 
 	/* Destination. */
 	p = ifc->destination;
-	if (p)
+	if (p) {
 		stream_put(s, &p->u.prefix, blen);
-	else
+		stream_putc(s, p->prefixlen);
+	} else {
 		stream_put(s, NULL, blen);
+		stream_putc(s, 0);
+	}
 
 	/* Write packet size. */
 	stream_putw_at(s, 0, stream_get_endp(s));
