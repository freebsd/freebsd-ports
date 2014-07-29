*** nettest.c.orig	Thu Nov  5 15:52:58 1992
--- nettest.c	Sun Sep 19 17:33:02 1999
***************
*** 92,98 ****
--- 92,102 ----
  int	nodelay = 0;
  int	mesghdr = 0;
  
+ #ifdef BSD44
+ clock_t	times();
+ #else
  long	times();
+ #endif
  #if	!defined(CRAY) && !defined(SYSV)
  #define	GETTIMES(a, b)	ftime(&a); times(&b);
  #define	TIMETYPE	struct timeb
***************
*** 126,132 ****
  
  void do_children(), do_stream(), usage(), do_dgram(), prtimes();
  
! int read(), recv();
  
  int (*rfunc)() = read;
  
--- 130,137 ----
  
  void do_children(), do_stream(), usage(), do_dgram(), prtimes();
  
! int read();
! ssize_t recv();
  
  int (*rfunc)() = read;
  
***************
*** 550,556 ****
--- 555,565 ----
  			shutdown(s, 2);
  			exit(0);
  		}
+ #ifdef BSD44 
+ 		if (connect(s, (struct sockaddr *)&name, namesize) < 0) {
+ #else
  		if (connect(s, (char *)&name, namesize) < 0) {
+ #endif
  			perror("connect");
  			exit(1);
  		}
***************
*** 1160,1167 ****
  	*data = 0;
  	for (i = 0; i < nchunks; i++) {
  		ret = mesghdr ? sendmsg(s, &outmsg, 0)
! 			: sendto(s, data, chunksize, 0, (caddr_t)&name,
! 						namesize);
  
  		if (ret < 0) {
  			perror(mesghdr ? "sendmsg" : "sendto");
--- 1169,1176 ----
  	*data = 0;
  	for (i = 0; i < nchunks; i++) {
  		ret = mesghdr ? sendmsg(s, &outmsg, 0)
! 			: sendto(s, data, chunksize, 0, 
! 				(struct sockaddr *)&name, namesize);
  
  		if (ret < 0) {
  			perror(mesghdr ? "sendmsg" : "sendto");
***************
*** 1397,1408 ****
  	register char	*c;
  	int		tos;
  
  #ifdef	IP_TOS
  	struct tosent	*tosp;
  
! 	tosp = gettosbyname(name, proto);
  	if (tosp) {
! 		tos = tosp->t_tos;
  	} else {
  #endif
  		for (c = name; *c; c++) {
--- 1406,1418 ----
  	register char	*c;
  	int		tos;
  
+ #undef IP_TOS
  #ifdef	IP_TOS
  	struct tosent	*tosp;
  
! 	tosp = (struct tosent *)gettosbyname(name, proto);
  	if (tosp) {
! 		tos = (int)tosp->t_tos;
  	} else {
  #endif
  		for (c = name; *c; c++) {
