*** socket.c.orig	Fri Mar 22 11:42:23 2002
--- socket.c	Fri Mar 22 12:06:16 2002
***************
*** 9,14 ****
--- 9,17 ----
  
  #include <sys/types.h>
  #include <sys/socket.h>
+ #ifdef USE_INET6
+ #include <sys/time.h>
+ #endif /* USE_INET6 */
  #include <netinet/in.h>
  #include <netdb.h>
  #include <errno.h>
***************
*** 36,44 ****
  char *progname ;		/* name of the game */
  char *pipe_program = NULL ;	/* program to execute in two-way pipe */
  
  void server A((int port, char *service_name)) ;
- void handle_server_connection A((void)) ;
  void client A((char *host, int port, char *service_name)) ;
  extern void init_signals A((void)) ;
  extern void do_io A((void)) ;
  
--- 39,53 ----
  char *progname ;		/* name of the game */
  char *pipe_program = NULL ;	/* program to execute in two-way pipe */
  
+ #ifndef USE_INET6
  void server A((int port, char *service_name)) ;
  void client A((char *host, int port, char *service_name)) ;
+ #else /* USE_INET6 */
+ void server A((char *port)) ;
+ void client A((char *host, char *port)) ;
+ #endif /* USE_INET6 */
+ 
+ void handle_server_connection A((void)) ;
  extern void init_signals A((void)) ;
  extern void do_io A((void)) ;
  
***************
*** 51,58 ****
--- 60,69 ----
      int error = 0 ;		/* usage error occurred */
      extern int optind ;		/* from getopt() */
      /* char *host ; */		/* name of remote host */
+ #ifndef USE_INET6
      int port ;			/* port number for socket */
      char *service_name ;	/* name of service for port */
+ #endif /* USE_INET6 */
  
      /* print version ID if requested */
      if (argv[1] && !strcmp(argv[1], "-version")) {
***************
*** 62,68 ****
  
      /* set up progname for later use */
      progname = argv[0] ;
!     if ((cp = strrchr(progname, '/'))) progname = cp + 1 ;
  
      /* parse options */
      while ((opt = getopt(argc, argv, "bcflp:qrsvw?")) != -1) {
--- 73,80 ----
  
      /* set up progname for later use */
      progname = argv[0] ;
!     cp = strrchr(progname, '/');
!     if (cp) progname = cp + 1 ;
  
      /* parse options */
      while ((opt = getopt(argc, argv, "bcflp:qrsvw?")) != -1) {
***************
*** 130,135 ****
--- 142,148 ----
      /* set up signal handling */
      init_signals() ;
  
+ #ifndef USE_INET6
      /* get port number */
      port = resolve_service(argv[optind + 1 - serverflag],
  			   "tcp", &service_name) ;
***************
*** 138,178 ****
--- 151,231 ----
  	exit(5) ;
      }
  
+ #endif /* not USE_INET6 */
      /* and go */
      if (serverflag) {
  	if (backgflag) {
  	    background() ;
  	}
+ #ifndef USE_INET6
  	server(port, service_name) ;
+ #else /* USE_INET6 */
+ 	server(argv[optind]) ;
+ #endif /* USE_INET6 */
      } else {
+ #ifndef USE_INET6
  	client(argv[optind], port, service_name) ;
+ #else /* USE_INET6 */
+ 	client(argv[optind], argv[optind + 1]) ;
+ #endif /* USE_INET6 */
      }	       
      exit(0) ;
  }
  
  
+ #ifndef USE_INET6
  void server(port, service_name)
  int port ;
  char *service_name ;
+ #else /* USE_INET6 */
+ void server(port)
+ char *port ;
+ #endif /* USE_INET6 */
  {
+ #ifndef USE_INET6
      int socket_handle, alen ;
+ #else /* USE_INET6 */
+     int *socket_handle_list ;
+ #endif /* USE_INET6 */
  
      /* allocate server socket */
+ #ifndef USE_INET6
      socket_handle = create_server_socket(port, 1) ;
      if (socket_handle < 0) {
+ #else /* USE_INET6 */
+     socket_handle_list = create_server_sockets(&port, 1) ;
+     if (!socket_handle_list) {
+ #endif /* USE_INET6 */
  	perror2("server socket") ;
  	exit(1) ;
      }
+ #ifdef USE_INET6
+ 
+ #endif /* USE_INET6 */
      if (verboseflag) {
+ #ifndef USE_INET6
  	fprintf(stderr, "listening on port %d", port) ;
  	if (service_name) {
  	    fprintf(stderr, " (%s)", service_name) ;
  	}
  	fprintf(stderr, "\n") ;
+ #else /* USE_INET6 */
+ 	char *ip, *port;
+ 	int fd, i;
+ 
+ 	fd = socket_handle_list[1];
+ 	for (i = 1; i <= socket_handle_list[0]; i++) {
+     	    if (!fd || fd < socket_handle_list[i])
+        	        fd = socket_handle_list[i];
+ 	    socket_local_name (fd, NULL, &ip, &port);
+ 	    fprintf(stderr, "listening at address %s on port %s\n", ip, port) ;
+     	}
+ #endif /* USE_INET6 */
      }
  
      /* server loop */
      do {
+ #ifndef USE_INET6
  	struct sockaddr_in sa ;
  	    
  	alen = sizeof(sa) ;
***************
*** 189,204 ****
  		long norder ;
  		char dotted[20] ;
  
! 		he = gethostbyaddr((char *)&sa.sin_addr.s_addr,
  				   sizeof(sa.sin_addr.s_addr), AF_INET) ;
  		if (!he) {
  		    norder = htonl(sa.sin_addr.s_addr) ;
  		    sprintf(dotted, "%d.%d.%d.%d",
! 			    (int)((norder >> 24) & 0xff),
! 			    (int)((norder >> 16) & 0xff),
! 			    (int)((norder >>  8) & 0xff),
! 			    (int)(norder & 0xff)) ;
  		}
  		fprintf(stderr, "connection from %s\n",
  			(he ? he->h_name : dotted)) ;
  	    }
--- 242,317 ----
  		long norder ;
  		char dotted[20] ;
  
! 		he = gethostbyaddr((const char *)&sa.sin_addr.s_addr,
  				   sizeof(sa.sin_addr.s_addr), AF_INET) ;
  		if (!he) {
  		    norder = htonl(sa.sin_addr.s_addr) ;
  		    sprintf(dotted, "%d.%d.%d.%d",
!                            (int)((norder >> 24) & 0xff),
!                            (int)((norder >> 16) & 0xff),
!                            (int)((norder >>  8) & 0xff),
!                            (int)(norder & 0xff)) ;
! #else /* USE_INET6 */
! 	struct timeval tv;
! 	fd_set readfd;
!     	int fd, i, nfds, retval;
! 
! 	fd = socket_handle_list[1];
! 	for (i = 1; i <= socket_handle_list[0]; i++) {
!     	    if (!fd || fd < socket_handle_list[i])
!        	        fd = socket_handle_list[i];
!     	}
! 	nfds=fd+1;
! 
! 	FD_ZERO(&readfd);
! 	for (i = 1; i <= socket_handle_list[0]; i++)
! 	    FD_SET(socket_handle_list[i],&readfd);
! 
!     	tv.tv_sec  = 10;
!     	tv.tv_usec = 0;
! 
!     	retval = select(nfds, &readfd, NULL, NULL, &tv);
! 
!     	if(retval!=-1) {
!             for (i = 1; i <= socket_handle_list[0]; i++) {
! 		fd = socket_handle_list[i];
! 		if (FD_ISSET(fd, &readfd)) {
! 
! 		    /* accept a connection */
! 		    active_socket = accept(fd, (struct sockaddr *) 0, (int *)0);
! 		    if (active_socket == -1) {
! 			perror2("accept") ;
! 		    } else {
! 			/* if verbose, get name of peer and give message */
! 			if (verboseflag) {
! 			    char *host, *ip, *port;
! 
! 			    if(!socket_remote_name(active_socket,&host, &ip, &port)) {
! 				fprintf(stderr, "connection from %s at %s to %s\n", host, ip, port);
! 			    }
! 			    else
! 				fprintf(stderr, "cannot get name or address of peer") ;
! 			}
! 
! 			if (forkflag) {
! 			    switch (fork()) {
! 			    case 0:
! 				handle_server_connection() ;
! 				exit(0) ;
! 			    case -1:
! 				perror2("fork") ;
! 				break ;
! 			    default:
! 				close(active_socket) ;
! 				wait_for_children() ;
! 			    }
! 			} else {
! 			    handle_server_connection() ;
! 			}
! 		    }
! #endif /* USE_INET6 */
  		}
+ #ifndef USE_INET6
  		fprintf(stderr, "connection from %s\n",
  			(he ? he->h_name : dotted)) ;
  	    }
***************
*** 216,224 ****
--- 329,342 ----
  		}
  	    } else {
  		handle_server_connection() ;
+ #endif /* not USE_INET6 */
  	    }
  	}
      } while (loopflag) ;
+ #ifdef USE_INET6
+ 
+     free (socket_handle_list);
+ #endif /* USE_INET6 */
  }
  
  
***************
*** 239,251 ****
--- 357,381 ----
  }
  
  
+ #ifndef USE_INET6
  void client(host, port, service_name)
+ #else /* USE_INET6 */
+ void client(host, port)
+ #endif /* USE_INET6 */
  char *host ;
+ #ifndef USE_INET6
  int port ;
  char *service_name ;
+ #else /* USE_INET6 */
+ char *port ;
+ #endif /* USE_INET6 */
  {
      /* get connection */
+ #ifndef USE_INET6
      active_socket = create_client_socket(&host, port) ;
+ #else /* USE_INET6 */
+     active_socket = create_client_socket(&host, &port) ;
+ #endif /* USE_INET6 */
      if (active_socket == -1) {
  	perror2("client socket") ;
  	exit(errno) ;
***************
*** 254,264 ****
--- 384,401 ----
  	exit(13) ;
      }
      if (verboseflag) {
+ #ifndef USE_INET6
  	fprintf(stderr, "connected to %s port %d", host, port) ;
  	if (service_name) {
  	    fprintf(stderr, " (%s)", service_name) ;
  	}
  	fprintf(stderr, "\n") ;
+ #else /* USE_INET6 */
+ 	char *host, *ip, *port;
+ 
+ 	socket_local_name (active_socket, &host, &ip, &port);
+ 	fprintf(stderr, "connected to %s with address %s at port %s\n", host, ip, port) ;
+ #endif /* USE_INET6 */
      }
  
      /* open pipes to program if requested */
