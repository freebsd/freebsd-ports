*** smtp.c.orig	Thu Mar 10 06:10:48 2005
--- smtp.c	Thu Mar 24 11:38:42 2005
***************
*** 50,55 ****
--- 50,59 ----
  #define SMTP_CMD_PERM(x)	(500 <= (x) && (x) < 600)
  #define SMTP_DATA_OK(x)		((x) == 354)
  
+ #ifndef MSG_NOSIGNAL
+ 	#define MSG_NOSIGNAL 0
+ #endif
+ 
  typedef union {
      HEADER hdr;
      u_char buf[MAXPACKET];
***************
*** 326,333 ****
  	int optval = 1;
  	char buffer[8192];
  
! 	if ((gethostbyname_r(mxhost, &host_buf, buffer, sizeof(buffer),
! 	    &host, &ret))) return -1;
  
  	memset(&address, 0, sizeof(struct sockaddr));
  	address.sin_addr.s_addr = *(uint32_t *)host->h_addr_list[0];
--- 330,338 ----
  	int optval = 1;
  	char buffer[8192];
  
! 	host = gethostbyname_r(mxhost, &host_buf, buffer, sizeof(buffer), &ret);
! 	if(ret)
! 		return -1;
  
  	memset(&address, 0, sizeof(struct sockaddr));
  	address.sin_addr.s_addr = *(uint32_t *)host->h_addr_list[0];
