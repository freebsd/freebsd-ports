--- ./xio-listen.c.orig	Sun Jan 29 14:33:07 2006
+++ ./xio-listen.c	Sat Apr 29 15:33:10 2006
@@ -311,6 +311,7 @@
 		&ri, xfd->fd, &la->soa, pa, libwrapname);
 	 request_init(&ri, RQ_FILE, xfd->fd, RQ_CLIENT_SIN, &la->soa,
 		      RQ_SERVER_SIN, pa, RQ_DAEMON, libwrapname, 0);
+	 sock_methods(&ri);
 	 Debug("request_init() ->");
 
 	 Debug1("hosts_access(%p)", &ri);
