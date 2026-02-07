--- xa_input.c.orig	1999-03-21 22:36:25 UTC
+++ xa_input.c
@@ -1025,28 +1025,28 @@ char *machine, *user_cmd, *passwd_cmd, *file_cmd;
   memset(&data,0,sizeof(data));
   memset(&from,0,sizeof(from));
   if (gethostname(hostname, sizeof(hostname)) < 0)
-						return(xa_ftp_abort(xin));
+						return(xa_ftp_abort(*xin));
   if ((host= (struct hostent *)gethostbyname(hostname)) == 0)
-						return(xa_ftp_abort(xin));
+						return(xa_ftp_abort(*xin));
   data.sin_family = host->h_addrtype;
   memcpy( (char *)&data.sin_addr, (char *)host->h_addr_list[0], host->h_length);
   if ((tmp_sock = socket ( AF_INET  , SOCK_STREAM , 0 )) < 0)
-						return(xa_ftp_abort(xin));
+						return(xa_ftp_abort(*xin));
   len = 1;
   if (setsockopt(tmp_sock, SOL_SOCKET, SO_REUSEADDR,
 			(char *)(&len), sizeof(len)) < 0)
-			{ close(tmp_sock); return(xa_ftp_abort(xin)); }
+			{ close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
   data.sin_port = 0;
   if ( bind(tmp_sock, (struct sockaddr *)&data, sizeof(data)) < 0 )
-			{ close(tmp_sock); return(xa_ftp_abort(xin)); }
+			{ close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
   len = sizeof(data);
   if (getsockname(tmp_sock, (struct sockaddr *)&data, &len) < 0 )
-			{ close(tmp_sock); return(xa_ftp_abort(xin)); }
+			{ close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
   if (listen(tmp_sock, 4) < 0 )
-			{ close(tmp_sock); return(xa_ftp_abort(xin)); }
+			{ close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
      /* POD add support for PORT command? */
   addr = (xaUBYTE *) (&data.sin_addr);
@@ -1059,15 +1059,15 @@ char *machine, *user_cmd, *passwd_cmd, *file_cmd;
 
   if (xa_ftp_send_cmd(xin, port_cmd, &retcode) == xaFALSE) 
 	{ fprintf(stderr,"FTP: send cmd err\n"); 
-	  close(tmp_sock); return(xa_ftp_abort(xin)); }
+	  close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
   if (xa_ftp_send_cmd(xin, file_cmd, &retcode) == xaFALSE) 
 	{ fprintf(stderr,"FTP: send cmd err\n"); 
-	  close(tmp_sock); return(xa_ftp_abort(xin)); }
+	  close(tmp_sock); return(xa_ftp_abort(*xin)); }
 
   len = sizeof(from);
   xin->dsock = accept((int)tmp_sock, (struct sockaddr *) &from, (int *)&len);
-  if (xin->dsock < 0) { close(tmp_sock); return(xa_ftp_abort(xin)); }
+  if (xin->dsock < 0) { close(tmp_sock); return(xa_ftp_abort(*xin)); }
   close(tmp_sock);
   return(xaTRUE);
 }
