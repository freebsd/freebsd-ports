*** tcpmonitor.c.orig	Fri Jul 23 16:58:24 1999
--- tcpmonitor.c	Sun Apr  1 15:32:49 2001
***************
*** 12,18 ****
--- 12,20 ----
  #include <sys/time.h>
  #include <arpa/inet.h>
  #include <stdlib.h>
+ #ifndef __FreeBSD__
  #include <malloc.h>
+ #endif
  #include <fcntl.h>
  #include <errno.h>
  #include "config.h"
***************
*** 51,57 ****
  	if (debug)
  	fprintf(stderr,"trying to connect (tcp) to port %d at %s...\n", h->tcpport,
  	    inet_ntoa(h->tcpsock->sin_addr));
! 	if (connect(h->tcp_socket, (struct sockaddr_in*)h->tcpsock, 
  	        sizeof(struct sockaddr_in))<0) 
  	   switch(errno) {
  		case EISCONN: /* Common.. reported by lots of users 
--- 53,59 ----
  	if (debug)
  	fprintf(stderr,"trying to connect (tcp) to port %d at %s...\n", h->tcpport,
  	    inet_ntoa(h->tcpsock->sin_addr));
! 	if (connect(h->tcp_socket, (struct sockaddr*)h->tcpsock, 
  	        sizeof(struct sockaddr_in))<0) 
  	   switch(errno) {
  		case EISCONN: /* Common.. reported by lots of users 
