--- servers/slapd/daemon.c.orig	Sat Sep 30 11:24:28 2000
+++ servers/slapd/daemon.c	Tue Oct 31 10:54:09 2000
@@ -1,4 +1,4 @@
-/* $OpenLDAP: pkg/ldap/servers/slapd/daemon.c,v 1.99.2.12 2000/09/30 16:24:28 kurt Exp $ */
+/* $OpenLDAP: servers/slapd/daemon.c,v 1.99.2.13 2000/10/30 18:14:51 kurt Exp $ */
 /*
  * Copyright 1998-2000 The OpenLDAP Foundation, All Rights Reserved.
  * COPYING RESTRICTIONS APPLY, see COPYRIGHT file
@@ -59,6 +59,8 @@
 
 Listener **slap_listeners = NULL;
 
+#define SLAPD_LISTEN 10
+
 static ber_socket_t wake_sds[2];
 
 #ifdef NO_THREADS
@@ -81,8 +83,6 @@
 #endif
 volatile sig_atomic_t slapd_shutdown = 0;
 
-static ldap_pvt_thread_t	listener_tid;
-
 static struct slap_daemon {
 	ldap_pvt_thread_mutex_t	sd_mutex;
 
@@ -193,20 +193,207 @@
 	tcp_close(s);
 }
 
+static void slap_free_listener_addresses(struct sockaddr **sal)
+{
+	struct sockaddr **sap;
+
+	if (sal == NULL) {
+		return;
+	}
+
+	for (sap = sal; *sap != NULL; sap++) {
+		ch_free(*sap);
+	}
+
+	ch_free(sal);
+}
+
+/* port = 0 indicates AF_LOCAL */
+static int slap_get_listener_addresses(
+	const char *host,
+	unsigned short port,
+	struct sockaddr ***sal)
+{
+	struct sockaddr **sap;
+#ifdef HAVE_GETADDRINFO
+	struct addrinfo hints, *res, *sai;
+	int n, err;
+	
+	memset( &hints, '\0', sizeof(hints) );
+	hints.ai_flags = AI_PASSIVE;
+	hints.ai_socktype = SOCK_STREAM;
+#  ifdef LDAP_PF_LOCAL
+	if ( port == 0 ) {
+		hints.ai_family = AF_LOCAL;
+		/* host specifies a service in this case */
+		if (err = getaddrinfo(NULL, host, &hints, &res)) {
+			if (err == EAI_FAMILY) {
+				/* XXX Fake it */
+				struct sockaddr_un *sun = calloc(1, sizeof(struct sockaddr_un));
+				err = 0;
+				res = calloc(1, sizeof(*res));
+				assert(sun != NULL);
+				assert(res != NULL);
+				res->ai_flags = hints.ai_flags;
+				res->ai_family = AF_LOCAL;
+				res->ai_socktype = hints.ai_socktype;
+				res->ai_addr = (struct sockaddr *)sun;
+				res->ai_addrlen = sizeof(*sun);
+				sun->sun_len = strlen(LDAPI_SOCK) + 1;
+				sun->sun_family = AF_LOCAL;
+				strcpy(sun->sun_path, LDAPI_SOCK);
+			} else {
+				Debug( LDAP_DEBUG_ANY, "daemon: getaddrinfo failed: %s\n",
+				    gai_strerror(err), 0, 0);
+				return -1;
+			}
+		}
+	} else
+#  endif
+	{		
+		char serv[7];
+	
+		snprintf(serv, sizeof serv, "%d", port);
+		hints.ai_family = AF_UNSPEC;
+		if (err = getaddrinfo(host, serv, &hints, &res)) {
+			Debug( LDAP_DEBUG_ANY, "daemon: getaddrinfo failed: %s\n",
+				gai_strerror(err), 0, 0);
+			return -1;
+		}
+	}
+
+	sai = res;
+	for (n=2; (sai = sai->ai_next) != NULL; n++) {
+		/* EMPTY */ ;
+	}
+	*sal = ch_malloc(n * sizeof(*sal));
+	if (*sal == NULL) {
+		return -1;
+	}
+
+	sai = res;
+	sap = *sal;
+	do {
+		switch (sai->ai_family) {
+#  ifdef LDAP_PF_LOCAL
+		case AF_LOCAL: {
+			*sap = ch_malloc(sizeof(struct sockaddr_un));
+			if (*sap == NULL) {
+				freeaddrinfo(res);
+				goto errexit;
+			}
+			*(struct sockaddr_un *)*sap =
+				*((struct sockaddr_un *)sai->ai_addr);
+		} break;
+#  endif
+#  ifdef LDAP_PF_INET6			
+		case AF_INET6: {
+			*sap = ch_malloc(sizeof(struct sockaddr_in6));
+			if (*sap == NULL) {
+				freeaddrinfo(res);
+				goto errexit;
+			}
+			*(struct sockaddr_in6 *)*sap =
+				*((struct sockaddr_in6 *)sai->ai_addr);
+		} break;
+#  endif
+		case AF_INET: {
+			*sap = ch_malloc(sizeof(struct sockaddr_in));
+			if (*sap == NULL) {
+				freeaddrinfo(res);
+				goto errexit;
+			}
+			*(struct sockaddr_in *)*sap =
+				*((struct sockaddr_in *)sai->ai_addr);
+		} break;
+		default: 
+			*sap = NULL;
+			break;
+		}
+		if (*sap != NULL) {
+			(*sap)->sa_family = sai->ai_family;
+			sap++;
+		}
+	} while ((sai = sai->ai_next) != NULL);
+
+	freeaddrinfo(res);
+
+#else
+#  ifdef LDAP_PF_LOCAL
+	if ( port == 0 ) {
+		*sal = ch_malloc(2 * sizeof(*sal));
+		if (*sal == NULL) {
+			return -1;
+		}
+		sap = *sal;
+		*sap = ch_malloc(sizeof(struct sockaddr_un));
+		if (*sap == NULL)
+			goto errexit;
+		(void)memset( (void *)*sap, '\0', sizeof(struct sockaddr_un) );
+		(*sap)->sa_family = AF_LOCAL;
+		if ( strlen(host) >
+		     (sizeof(((struct sockaddr_un *)*sal)->sun_path) - 1) ) {
+			Debug( LDAP_DEBUG_ANY,
+			       "daemon: domain socket path (%s) too long in URL",
+			       host, 0, 0);
+			goto errexit;
+		}
+		strcpy( ((struct sockaddr_un *)*sap)->sun_path, host );
+	} else
+#  endif		
+	{
+		struct in_addr in;
+
+		if ( host == NULL ) {
+			in.s_addr = htonl(INADDR_ANY);
+
+		} else if ( !inet_aton( host, &in ) ) {
+			struct hostent *he = gethostbyname( host );
+			if( he == NULL ) {
+				Debug( LDAP_DEBUG_ANY,
+				       "daemon: invalid host %s", host, 0, 0);
+				return -1;
+			}
+			AC_MEMCPY( &in, he->h_addr, sizeof( in ) );
+		}
+
+		*sal = ch_malloc(2 * sizeof(*sal));
+		if (*sal == NULL) {
+			return -1;
+		}
+
+		sap = *sal;
+		*sap = ch_malloc(sizeof(struct sockaddr_in));
+		if (*sap == NULL) {
+			goto errexit;
+		}
+
+		(void)memset( (void *)*sap, '\0', sizeof(struct sockaddr_in) );
+		(*sap)->sa_family = AF_INET;
+		((struct sockaddr_in *)*sap)->sin_port = htons(port);
+		((struct sockaddr_in *)*sap)->sin_addr = in;
+	}
+	sap++;
+#endif
+
+	*sap = NULL;
+	return 0;
+
+errexit:
+	slap_free_listener_addresses(*sal);
+	return -1;
+}
 
-static Listener * open_listener( const char* url )
+static Listener * slap_open_listener(
+	const char* url )
 {
 	int	tmp, rc;
 	Listener l;
 	Listener *li;
 	LDAPURLDesc *lud;
-	char *s;
-	int port;
-#ifdef HAVE_GETADDRINFO
-	char serv[7];
-	struct addrinfo hints, *res, *sai;
-	int err;
-#endif
+	unsigned short port;
+	int err, addrlen;
+	struct sockaddr **sal, **psal;
 
 	rc = ldap_url_parse( url, &lud );
 
@@ -238,291 +425,171 @@
 	}
 #endif
 
-#ifdef HAVE_GETADDRINFO
-	memset( &hints, '\0', sizeof(hints) );
-	hints.ai_flags = AI_PASSIVE;
-	hints.ai_family = AF_UNSPEC;
-	hints.ai_socktype = SOCK_STREAM;
-
-#  ifdef LDAP_PF_LOCAL
+	port = (unsigned short) lud->lud_port;
+	
 	if ( ldap_pvt_url_scheme2proto(lud->lud_scheme) == LDAP_PROTO_IPC ) {
+#ifdef LDAP_PF_LOCAL
 		if ( lud->lud_host == NULL || lud->lud_host[0] == '\0' ) {
-			err = getaddrinfo(NULL, LDAPI_SOCK, &hints, &res);
-			if (!err)
-				unlink( LDAPI_SOCK );
+			err = slap_get_listener_addresses(LDAPI_SOCK, 0, &sal);
 		} else {
-			err = getaddrinfo(NULL, lud->lud_host, &hints, &res);
-			if (!err)
-				unlink( lud->lud_host );
+			err = slap_get_listener_addresses(lud->lud_host, 0, &sal);
 		}
-	} else
-#  endif /* LDAP_PF_LOCAL */
-	{
-		snprintf(serv, sizeof serv, "%d", lud->lud_port);
+#else
+		Debug( LDAP_DEBUG_ANY, "daemon: URL scheme not supported: %s",
+			url, 0, 0);
+		ldap_free_urldesc( lud );
+		return NULL;
+#endif
+	} else {
 		if( lud->lud_host == NULL || lud->lud_host[0] == '\0'
 			|| strcmp(lud->lud_host, "*") == 0 )
 		{
-			err = getaddrinfo(NULL, serv, &hints, &res);
+			err = slap_get_listener_addresses(NULL, port, &sal);
 		} else {
-			err = getaddrinfo(lud->lud_host, serv, &hints, &res);
+			err = slap_get_listener_addresses(lud->lud_host, port, &sal);
 		}
 	}
 
+	ldap_free_urldesc( lud );
 	if ( err ) {
-		Debug( LDAP_DEBUG_ANY, "daemon: getaddrinfo failed\n", 0, 0, 0);
-		ldap_free_urldesc( lud );
 		return NULL;
 	}
 
-	ldap_free_urldesc( lud );
-	sai = res;
-	do {
-		if ( (sai->ai_family != AF_INET)
-#  ifdef LDAP_PF_INET6
-		     && (sai->ai_family != AF_INET6)
-#  endif
-#  ifdef LDAP_PF_LOCAL
-		     && (sai->ai_family != AF_LOCAL)
-#  endif
-		     )
+	psal = sal;
+	while ( *sal != NULL ) {
+		switch( (*sal)->sa_family ) {
+		case AF_INET:
+#ifdef LDAP_PF_INET6
+		case AF_INET6:
+#endif
+#ifdef LDAP_PF_LOCAL
+		case AF_LOCAL:
+#endif
+			break;
+		default:
+			sal++;
 			continue;
-		l.sl_sd = socket( sai->ai_family, sai->ai_socktype, sai->ai_protocol);
+		}
+		l.sl_sd = socket( (*sal)->sa_family, SOCK_STREAM, 0);
 		if ( l.sl_sd == AC_SOCKET_INVALID ) {
 			int err = sock_errno();
 			Debug( LDAP_DEBUG_ANY,
 				"daemon: socket() failed errno=%d (%s)\n", err,
 				sock_errstr(err), 0 );
+			sal++;
 			continue;
 		}
-
-		if ( sai->ai_family != AF_LOCAL ) {
-#else
-
-	if ( ldap_pvt_url_scheme2proto(lud->lud_scheme) == LDAP_PROTO_IPC ) {
+#ifndef HAVE_WINSOCK
+		if ( l.sl_sd >= dtblsize ) {
+			Debug( LDAP_DEBUG_ANY,
+			       "daemon: listener descriptor %ld is too great %ld\n",
+			       (long) l.sl_sd, (long) dtblsize, 0 );
+			tcp_close( l.sl_sd );
+			sal++;
+			continue;
+		}
+#endif
 #ifdef LDAP_PF_LOCAL
-		port = 0;
-		(void) memset( (void *)&l.sl_sa.sa_un_addr, '\0', sizeof(l.sl_sa.sa_un_addr) );
-
-		l.sl_sa.sa_un_addr.sun_family = AF_LOCAL;
-
-		/* hack: overload the host to be the path */
-		if ( lud->lud_host == NULL || lud->lud_host[0] == '\0' ) {
-			strcpy( l.sl_sa.sa_un_addr.sun_path, LDAPI_SOCK );
-		} else {
-			if ( strlen(lud->lud_host) > (sizeof(l.sl_sa.sa_un_addr.sun_path) - 1) ) {
-				Debug( LDAP_DEBUG_ANY,
-					"daemon: domain socket path (%s) too long in URL: %s",
-					lud->lud_host, url, 0);
-				ldap_free_urldesc( lud );
-				return NULL;
-			}
-			strcpy( l.sl_sa.sa_un_addr.sun_path, lud->lud_host );
-		}
-		unlink( l.sl_sa.sa_un_addr.sun_path ); 
-#if 0
-		/* I don't think we need to set this. */
-		l.sl_sa.sa_un_addr.sun_len = sizeof( l.sl_sa.sa_un_addr.sun_len ) +
-			sizeof( l.sl_sa.sa_un_addr.sun_family ) +
-			strlen( l.sl_sa.sa_un_addr.sun_path ) + 1;
+		if ( (*sal)->sa_family == AF_LOCAL ) {
+			unlink ( ((struct sockaddr_un *)*sal)->sun_path );
+		} else
 #endif
-#else
-		Debug( LDAP_DEBUG_ANY, "daemon: URL scheme not supported: %s",
-			url, 0, 0);
-		ldap_free_urldesc( lud );
-		return NULL;
-#endif /* LDAP_PF_LOCAL */
-	} else {
-
-	port = lud->lud_port;
-
-	(void) memset( (void*) &l.sl_addr, '\0', sizeof(l.sl_addr) );
-
-	l.sl_addr.sin_family = AF_INET;
-	l.sl_addr.sin_port = htons( (unsigned short) lud->lud_port );
-
-	if( lud->lud_host == NULL || lud->lud_host[0] == '\0'
-		|| strcmp(lud->lud_host, "*") == 0 )
-	{
-		l.sl_addr.sin_addr.s_addr = htonl(INADDR_ANY);
-
-	} else {
-		/* host or address was specified */
-		if( !inet_aton( lud->lud_host, &l.sl_addr.sin_addr ) ) {
-			struct hostent *he = gethostbyname( lud->lud_host );
-			if( he == NULL ) {
+		{
+#ifdef SO_REUSEADDR
+			/* enable address reuse */
+			tmp = 1;
+			rc = setsockopt( l.sl_sd, SOL_SOCKET, SO_REUSEADDR,
+					 (char *) &tmp, sizeof(tmp) );
+			if ( rc == AC_SOCKET_ERROR ) {
+				int err = sock_errno();
 				Debug( LDAP_DEBUG_ANY,
-					"daemon: invalid host (%s) in URL: %s",
-					lud->lud_host, url, 0);
-				ldap_free_urldesc( lud );
-				return NULL;
+				       "slapd(%ld): setsockopt(SO_REUSEADDR) failed errno=%d (%s)\n",
+				       (long) l.sl_sd, err, sock_errstr(err) );
 			}
-
-			AC_MEMCPY( &l.sl_addr.sin_addr, he->h_addr,
-			       sizeof( l.sl_addr.sin_addr ) );
+#endif
 		}
-	}
-	}
-
-	ldap_free_urldesc( lud );
-
-	l.sl_sd = socket( l.sl_sa.sa_addr.sa_family, SOCK_STREAM, 0 );
-	if ( l.sl_sd == AC_SOCKET_INVALID ) {
-		int err = sock_errno();
-		Debug( LDAP_DEBUG_ANY,
-			"daemon: socket() failed errno=%d (%s)\n", err,
-			sock_errstr(err), 0 );
-		return NULL;
-	}
-
-#ifndef HAVE_WINSOCK
-	if ( l.sl_sd >= dtblsize ) {
-		Debug( LDAP_DEBUG_ANY,
-			"daemon: listener descriptor %ld is too great %ld\n",
-			(long) l.sl_sd, (long) dtblsize, 0 );
-		tcp_close( l.sl_sd );
-		return NULL;
-	}
+	
+		switch( (*sal)->sa_family ) {
+		case AF_INET:
+			addrlen = sizeof(struct sockaddr_in);
+			break;
+#ifdef LDAP_PF_INET6
+		case AF_INET6:
+			addrlen = sizeof(struct sockaddr_in6);
+			break;
 #endif
-
 #ifdef LDAP_PF_LOCAL
-	/* for IPv4 and IPv6 sockets only */
-	if ( l.sl_sa.sa_addr.sa_family != AF_LOCAL ) {
-#endif /* LDAP_PF_LOCAL */
-#endif /* HAVE_GETADDRINFO */
-
-#ifdef SO_REUSEADDR
-	/* enable address reuse */
-	tmp = 1;
-	rc = setsockopt( l.sl_sd, SOL_SOCKET, SO_REUSEADDR,
-		(char *) &tmp, sizeof(tmp) );
-	if ( rc == AC_SOCKET_ERROR ) {
-		int err = sock_errno();
-		Debug( LDAP_DEBUG_ANY,
-	       "slapd(%ld): setsockopt(SO_REUSEADDR) failed errno=%d (%s)\n",
-	    	(long) l.sl_sd, err, sock_errstr(err) );
-	}
+		case AF_LOCAL:
+			addrlen = sizeof(struct sockaddr_un);
+			break;
 #endif
-
-#ifdef HAVE_GETADDRINFO
-		} /* sai->ai_family != AF_LOCAL */
-		if (!bind(l.sl_sd, sai->ai_addr, sai->ai_addrlen))
+		}
+	
+		if (!bind(l.sl_sd, *sal, addrlen))
 			break;
 		err = sock_errno();
 		Debug( LDAP_DEBUG_ANY, "daemon: bind(%ld) failed errno=%d (%s)\n",
-			(long) l.sl_sd, err, sock_errstr(err) );
+		       (long) l.sl_sd, err, sock_errstr(err) );
 		tcp_close( l.sl_sd );
-	} while ((sai = sai->ai_next) != NULL);
+		sal++;
+	} /* while ( *sal != NULL ) */
 
-	if (!sai) {
+	if ( *sal == NULL ) {
 		Debug( LDAP_DEBUG_ANY, "daemon: bind(%ld) failed\n",
 			(long) l.sl_sd, 0, 0 );
+		slap_free_listener_addresses(psal);
 		return NULL;
 	}
 
-	switch ( sai->ai_family ) {
-#  ifdef LDAP_PF_LOCAL
-	case AF_LOCAL:
-		if ( chmod( (char *)sai->ai_addr, S_IRWXU ) < 0 ) {
+	switch ( (*sal)->sa_family ) {
+#ifdef LDAP_PF_LOCAL
+	case AF_LOCAL: {
+		char *addr = ((struct sockaddr_un *)*sal)->sun_path;
+		if ( chmod( addr, S_IRWXU ) < 0 ) {
 			int err = sock_errno();
 			Debug( LDAP_DEBUG_ANY, "daemon: fchmod(%ld) failed errno=%d (%s)",
-				(long) l.sl_sd, err, sock_errstr(err) );
+			       (long) l.sl_sd, err, sock_errstr(err) );
 			tcp_close( l.sl_sd );
+			slap_free_listener_addresses(psal);
 			return NULL;
 		}
-		l.sl_name = ch_malloc( strlen((char *)sai->ai_addr) + sizeof("PATH=") );
-		sprintf( l.sl_name, "PATH=%s", sai->ai_addr );
-		break;
-#  endif /* LDAP_PF_LOCAL */
+		l.sl_name = ch_malloc( strlen(addr) + sizeof("PATH=") );
+		sprintf( l.sl_name, "PATH=%s", addr );
+	} break;
+#endif /* LDAP_PF_LOCAL */
 
 	case AF_INET: {
+		char *s;
+#ifdef HAVE_GETADDRINFO		
 		char addr[INET_ADDRSTRLEN];
-		inet_ntop( AF_INET,
-			&((struct sockaddr_in *)sai->ai_addr)->sin_addr,
-			addr, sizeof(addr) );
-		l.sl_name = ch_malloc( strlen(addr) + strlen(serv) + sizeof("IP=:") );
-		sprintf( l.sl_name, "IP=%s:%s", addr, serv );
+		inet_ntop( AF_INET, &((struct sockaddr_in *)*sal)->sin_addr,
+			   addr, sizeof(addr) );
+		s = addr;
+#else
+		s = inet_ntoa( l.sl_addr.sin_addr );
+#endif		
+		l.sl_name = ch_malloc( sizeof("IP=255.255.255.255:65535") );
+		sprintf( l.sl_name, "IP=%s:%d",
+			 s != NULL ? s : "unknown" , port );
 	} break;
 
-#  ifdef LDAP_PF_INET6
+#ifdef LDAP_PF_INET6
 	case AF_INET6: {
 		char addr[INET6_ADDRSTRLEN];
-		inet_ntop( AF_INET6,
-			&((struct sockaddr_in6 *)sai->ai_addr)->sin6_addr,
-			addr, sizeof addr);
-		l.sl_name = ch_malloc( strlen(addr) + strlen(serv) + sizeof("IP= ") );
-		sprintf( l.sl_name, "IP=%s %s", addr, serv );
+		inet_ntop( AF_INET6, &((struct sockaddr_in6 *)*sal)->sin6_addr,
+			   addr, sizeof addr);
+		l.sl_name = ch_malloc( strlen(addr) + sizeof("IP= 65535") );
+		sprintf( l.sl_name, "IP=%s %d", addr, port );
 	} break;
-#  endif /* LDAP_PF_INET6 */
+#endif /* LDAP_PF_INET6 */
 
 	default:
 		Debug( LDAP_DEBUG_ANY, "daemon: unsupported address family (%d)\n",
-			(int) sai->ai_family, 0, 0 );
+			(int) (*sal)->sa_family, 0, 0 );
 		break;
 	}
-#else
-#ifdef LDAP_PF_LOCAL
-	/* close conditional */
-	}
-#endif /* LDAP_PF_LOCAL */
-
-	switch ( l.sl_sa.sa_addr.sa_family ) {
-#ifdef LDAP_PF_LOCAL
-		case AF_LOCAL:
-			rc = bind( l.sl_sd, (struct sockaddr *)&l.sl_sa,
-				sizeof(l.sl_sa.sa_un_addr) );
-			break;
-#endif
-
-		case AF_INET:
-			rc = bind( l.sl_sd, (struct sockaddr *)&l.sl_sa,
-				sizeof(l.sl_sa.sa_in_addr) );
-			break;
 
-		default:
-			rc = AC_SOCKET_ERROR;
-			errno = EINVAL;
-			break;
-	}
-
-	if ( rc == AC_SOCKET_ERROR ) {
-		int err = sock_errno();
-		Debug( LDAP_DEBUG_ANY, "daemon: bind(%ld) failed errno=%d (%s)\n",
-	    	(long) l.sl_sd, err, sock_errstr(err) );
-		tcp_close( l.sl_sd );
-		return NULL;
-	}
-
-	switch ( l.sl_sa.sa_addr.sa_family ) {
-#ifdef LDAP_PF_LOCAL
-		case AF_LOCAL:
-			if ( chmod( l.sl_sa.sa_un_addr.sun_path, S_IRWXU ) < 0 ) {
-				int err = sock_errno();
-				Debug( LDAP_DEBUG_ANY,
-					"daemon: chmod(%ld) failed errno=%d (%s)",
-					(long) l.sl_sd, err, sock_errstr(err) );
-				tcp_close( l.sl_sd );
-				return NULL;
-			}
-
-			l.sl_name = ch_malloc( strlen(l.sl_sa.sa_un_addr.sun_path)
-				+ sizeof("PATH=") );
-			sprintf( l.sl_name, "PATH=%s", l.sl_sa.sa_un_addr.sun_path );
-			break;
-#endif /* LDAP_PF_LOCAL */
-
-		case AF_INET:
-			l.sl_name = ch_malloc( sizeof("IP=255.255.255.255:65336") );
-			s = inet_ntoa( l.sl_addr.sin_addr );
-			sprintf( l.sl_name, "IP=%s:%d",
-				s != NULL ? s : "unknown" , port );
-			break;
-
-		default:
-			l.sl_name = ch_strdup( "UNKNOWN" );
-			break;
-	}
-
-#endif /* HAVE_GETADDRINFO */
+	slap_free_listener_addresses(psal);
 
 	l.sl_url = ch_strdup( url );
 	li = ch_malloc( sizeof( Listener ) );
@@ -608,7 +675,7 @@
 	slap_listeners = ch_malloc( (i+1)*sizeof(Listener *) );
 
 	for(i = 0; u[i] != NULL; i++ ) {
-		slap_listeners[i] = open_listener( u[i] );
+		slap_listeners[i] = slap_open_listener( u[i] );
 
 		if( slap_listeners[i] == NULL ) {
 			charray_free( u );
@@ -642,7 +709,6 @@
 	void *ptr
 )
 {
-	int rc, tmp;
 	int l;
 	time_t	last_idle_check = slap_get_time();
 	time( &starttime );
@@ -651,7 +717,7 @@
 		if ( slap_listeners[l]->sl_sd == AC_SOCKET_INVALID )
 			continue;
 
-		if ( listen( slap_listeners[l]->sl_sd, 5 ) == -1 ) {
+		if ( listen( slap_listeners[l]->sl_sd, SLAPD_LISTEN ) == -1 ) {
 			int err = sock_errno();
 			Debug( LDAP_DEBUG_ANY,
 				"daemon: listen(%s, 5) failed errno=%d (%s)\n",
@@ -814,7 +880,7 @@
 		}
 
 		for ( l = 0; slap_listeners[l] != NULL; l++ ) {
-			ber_int_t s;
+			ber_socket_t s;
 			socklen_t len = sizeof(from);
 			long id;
 			slap_ssf_t ssf = 0;
@@ -860,31 +926,6 @@
 			}
 #endif
 
-#ifdef SO_KEEPALIVE
-			/* enable keep alives */
-			rc = setsockopt( s, SOL_SOCKET, SO_KEEPALIVE,
-				(char *) &tmp, sizeof(tmp) );
-			if ( rc == AC_SOCKET_ERROR ) {
-				int err = sock_errno();
-				Debug( LDAP_DEBUG_ANY,
-					"slapd(%ld): setsockopt(SO_KEEPALIVE) failed "
-					"errno=%d (%s)\n", (long) s, err, sock_errstr(err) );
-			}
-#endif
-#ifdef TCP_NODELAY
-			/* enable no delay */
-			tmp = 1;
-			rc = setsockopt( s, IPPROTO_TCP, TCP_NODELAY,
-				(char *)&tmp, sizeof(tmp) );
-			if ( rc == AC_SOCKET_ERROR ) {
-				int err = sock_errno();
-				Debug( LDAP_DEBUG_ANY,
-					"slapd(%ld): setsockopt(TCP_NODELAY) failed "
-					"errno=%d (%s)\n", (long) s, err, sock_errstr(err) );
-			}
-#endif
-
-
 #ifdef LDAP_DEBUG
 			ldap_pvt_thread_mutex_lock( &slap_daemon.sd_mutex );
 
@@ -896,20 +937,44 @@
 			ldap_pvt_thread_mutex_unlock( &slap_daemon.sd_mutex );
 #endif
 
+#if defined( SO_KEEPALIVE ) || defined( TCP_NODELAY )
+#ifdef LDAP_PF_LOCAL
+			/* for IPv4 and IPv6 sockets only */
+			if ( from.sa_addr.sa_family != AF_LOCAL )
+#endif /* LDAP_PF_LOCAL */
+			{
+				int rc;
+				int tmp;
+#ifdef SO_KEEPALIVE
+				/* enable keep alives */
+				tmp = 1;
+				rc = setsockopt( s, SOL_SOCKET, SO_KEEPALIVE,
+					(char *) &tmp, sizeof(tmp) );
+				if ( rc == AC_SOCKET_ERROR ) {
+					int err = sock_errno();
+					Debug( LDAP_DEBUG_ANY,
+						"slapd(%ld): setsockopt(SO_KEEPALIVE) failed "
+						"errno=%d (%s)\n", (long) s, err, sock_errstr(err) );
+				}
+#endif
+#ifdef TCP_NODELAY
+				/* enable no delay */
+				tmp = 1;
+				rc = setsockopt( s, IPPROTO_TCP, TCP_NODELAY,
+					(char *)&tmp, sizeof(tmp) );
+				if ( rc == AC_SOCKET_ERROR ) {
+					int err = sock_errno();
+					Debug( LDAP_DEBUG_ANY,
+						"slapd(%ld): setsockopt(TCP_NODELAY) failed "
+						"errno=%d (%s)\n", (long) s, err, sock_errstr(err) );
+				}
+#endif
+			}
+#endif
+
 			Debug( LDAP_DEBUG_CONNS, "daemon: new connection on %ld\n",
 				(long) s, 0, 0 );
 
-			len = sizeof(from);
-
-			if ( getpeername( s, (struct sockaddr *) &from, &len ) != 0 ) {
-				int err = sock_errno();
-				Debug( LDAP_DEBUG_ANY,
-					"daemon: getpeername( %ld ) failed: errno=%d (%s)\n",
-					(long) s, err, sock_errstr(err) );
-				slapd_close(s);
-				continue;
-			}
-
 			switch ( from.sa_addr.sa_family ) {
 #  ifdef LDAP_PF_LOCAL
 			case AF_LOCAL:
@@ -948,6 +1013,7 @@
 				slapd_close(s);
 				continue;
 			}
+
 			if ( ( from.sa_addr.sa_family == AF_INET ) 
 #ifdef LDAP_PF_INET6
 				|| ( from.sa_addr.sa_family == AF_INET6 )
@@ -961,7 +1027,7 @@
 						sizeof(from.sa_in6_addr.sin6_addr),
 						AF_INET6 );
 				else
-#  endif LDAP_PF_INET6
+#  endif /* LDAP_PF_INET6 */
 				hp = gethostbyaddr(
 					(char *) &(from.sa_in_addr.sin_addr),
 					sizeof(from.sa_in_addr.sin_addr),
@@ -1202,23 +1268,25 @@
 	connections_init();
 
 #define SLAPD_LISTENER_THREAD 1
-#if defined( SLAPD_LISTENER_THREAD ) || !defined(HAVE_PTHREADS)
+#if defined( SLAPD_LISTENER_THREAD )
+	{
+		ldap_pvt_thread_t	listener_tid;
 
-	/* listener as a separate THREAD */
-	rc = ldap_pvt_thread_create( &listener_tid,
-		0, slapd_daemon_task, NULL );
+		/* listener as a separate THREAD */
+		rc = ldap_pvt_thread_create( &listener_tid,
+			0, slapd_daemon_task, NULL );
 
-	if ( rc != 0 ) {
-		Debug( LDAP_DEBUG_ANY,
-		    "listener ldap_pvt_thread_create failed (%d)\n", rc, 0, 0 );
-		return rc;
-	}
+		if ( rc != 0 ) {
+			Debug( LDAP_DEBUG_ANY,
+		    	"listener ldap_pvt_thread_create failed (%d)\n", rc, 0, 0 );
+			return rc;
+		}
 
-	/* wait for the listener thread to complete */
-	ldap_pvt_thread_join( listener_tid, (void *) NULL );
+		/* wait for the listener thread to complete */
+		ldap_pvt_thread_join( listener_tid, (void *) NULL );
+ 	}
 #else
-	/* expermimental code */
-	listener_tid = pthread_self();
+	/* experimental code */
 	slapd_daemon_task( NULL );
 #endif
 
@@ -1307,4 +1375,9 @@
 
 	/* reinstall self */
 	(void) SIGNAL_REINSTALL( sig, slap_sig_wake );
+}
+
+
+void slapd_add_internal(ber_socket_t s) {
+	slapd_add(s);
 }
