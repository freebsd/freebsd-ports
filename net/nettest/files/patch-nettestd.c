*** nettestd.c.orig	Thu Nov  5 15:52:58 1992
--- nettestd.c	Sun Sep 19 17:31:20 1999
***************
*** 107,113 ****
  } name;
  int namesize;
  
! int read(), recv();
  int (*rfunc)() = read;
  
  main(argc, argv)
--- 107,114 ----
  } name;
  int namesize;
  
! int read();
! ssize_t recv();
  int (*rfunc)() = read;
  
  main(argc, argv)
***************
*** 271,277 ****
  # endif
  #endif
  	if (daemon) {
! 		if (setpgrp() < 0)
  			perror("setpgrp");
  		if ((c = open(_PATH_TTY, O_RDWR)) >= 0) {
  			(void)ioctl(c, TIOCNOTTY, (char *)0);
--- 272,278 ----
  # endif
  #endif
  	if (daemon) {
! 		if (setpgrp(0, getpid()) < 0)
  			perror("setpgrp");
  		if ((c = open(_PATH_TTY, O_RDWR)) >= 0) {
  			(void)ioctl(c, TIOCNOTTY, (char *)0);
***************
*** 416,422 ****
  			    )
  			error("setsockopt (IP_OPTIONS)");
  #endif
! 		if (bind(s, (char *)&name, namesize) < 0) {
  			error("bind");
  			exit(1);
  		}
--- 417,423 ----
  			    )
  			error("setsockopt (IP_OPTIONS)");
  #endif
! 		if (bind(s, (struct sockaddr *)&name, namesize) < 0) {
  			error("bind");
  			exit(1);
  		}
***************
*** 447,456 ****
  #endif
  	listen(s, 5);
  
! 	signal(SIGCHLD, dochild);
  	for (;;) {
  		namesize = sizeof(name);
! 		s2 = accept(s, (char *)&name, &namesize);
  		if (s2 < 0) {
  			extern int errno;
  			if (errno == EINTR)
--- 448,457 ----
  #endif
  	listen(s, 5);
  
! 	signal(SIGCHLD, (void *)dochild);
  	for (;;) {
  		namesize = sizeof(name);
! 		s2 = accept(s, (struct sockaddr *)&name, &namesize);
  		if (s2 < 0) {
  			extern int errno;
  			if (errno == EINTR)
***************
*** 723,729 ****
  #endif
  		{
  			namesize = sizeof(name.d_inet);
! 			t = recvfrom(s, data, MAXSIZE, 0, (char *)&name.d_inet,
  				 &namesize);
  		}
  		if (t < 0) {
--- 724,730 ----
  #endif
  		{
  			namesize = sizeof(name.d_inet);
! 			t = recvfrom(s, data, MAXSIZE, 0, (struct sockaddr *)&name.d_inet,
  				 &namesize);
  		}
  		if (t < 0) {
