--- sp.c	Tue Aug  5 21:35:28 2003
+++ sp.c	Tue Aug  5 21:24:19 2003
@@ -551,7 +551,7 @@
 		Alarm( SESSION, "SP_connect: set sndbuf/rcvbuf to %d\n", 1024*(i-5) );
 
 		unix_addr.sun_family = AF_UNIX;
-		sprintf( unix_addr.sun_path, "/tmp/%d", port );
+		sprintf( unix_addr.sun_path, "%s/spread.sock", _PATH_SPREAD_PIDDIR );
 		while( ((ret = connect( s, (struct sockaddr *)&unix_addr, sizeof(unix_addr) )) == -1)
                        && ((sock_errno == EINTR) || (sock_errno == EAGAIN) || (sock_errno == EWOULDBLOCK)) )
                 {
