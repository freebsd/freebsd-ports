--- sp.c	Tue Oct  5 09:08:10 2004
+++ sp.c	Tue Oct  4 14:44:27 2005
@@ -591,7 +591,7 @@
                 set_large_socket_buffers(s);
 
 		unix_addr.sun_family = AF_UNIX;
-		sprintf( unix_addr.sun_path, "/tmp/%d", port );
+		sprintf( unix_addr.sun_path, "%s/spread.sock", _PATH_SPREAD_PIDDIR );
 		ret = connect_nointr_timeout( s, (struct sockaddr *)&unix_addr, sizeof(unix_addr), &time_out);
 #endif	/* !ARCH_PC_WIN95 */
 	}
