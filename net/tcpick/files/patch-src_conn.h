--- src/conn.h.orig	2020-08-25 17:08:29 UTC
+++ src/conn.h
@@ -80,5 +80,5 @@ struct CONN
 };
 
 
-struct ip * ip_last_header; /* FIXME: check */
-struct tcphdr * tcp_last_header;
+extern struct ip * ip_last_header; /* FIXME: check */
+extern struct tcphdr * tcp_last_header;
