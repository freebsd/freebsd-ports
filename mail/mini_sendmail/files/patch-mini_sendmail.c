--- mini_sendmail.c.orig	Thu Nov 21 23:27:55 2002
+++ mini_sendmail.c	Fri Aug 29 17:45:40 2003
@@ -575,14 +575,15 @@ open_client_socket( void )
     sock_family = PF_INET6;
 
 #ifdef DO_MINUS_S
-    if ( inet_pton( PF_INET, server, (void*) &sa4.sin_addr ) == 0 )
+	(void) memset( (void*) &sa4, 0, sizeof(sa4) );
+	if ( inet_pton( AF_INET, server, (void*) &sa4.sin_addr ) == 1 )
 	{
 	sock_family = PF_INET;
 	sa4.sin_port = htons( SMTP_PORT );
 	sa_len = sizeof(sa4);
 	(void) memmove( &sa, &sa4, sa_len );
 	}
-    else if ( inet_pton( PF_INET6, server, (void*) &sa.sin6_addr ) == -1 )
+	else if ( inet_pton( AF_INET6, server, (void*) &sa.sin6_addr ) != 1 )
 	{
 #ifdef DO_DNS
 	(void) memset( &hints, 0, sizeof(hints) );
