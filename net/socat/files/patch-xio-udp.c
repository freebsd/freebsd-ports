--- ./xio-udp.c.orig	Sat Apr 29 15:34:17 2006
+++ ./xio-udp.c	Sat Apr 29 15:34:32 2006
@@ -226,6 +226,7 @@
 		&ri, fd->stream.fd, &la->soa, them, libwrapname);
 	 request_init(&ri, RQ_FILE, fd->stream.fd, RQ_CLIENT_SIN, &la->soa,
 		      RQ_SERVER_SIN, them, RQ_DAEMON, libwrapname, 0);
+	 sock_methods(&ri);
 	 Debug("request_init() ->");
 
 	 Debug1("hosts_access(%p)", &ri);
