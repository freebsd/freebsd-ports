*** lib/krb/sendauth.c.orig	Thu Sep 16 15:41:55 1999
--- lib/krb/sendauth.c	Thu Feb 27 15:14:20 2003
***************
*** 103,109 ****
  	     u_int32_t checksum, /* checksum to include in request */
  	     MSG_DAT *msg_data,	/* mutual auth MSG_DAT (return) */
  	     CREDENTIALS *cred,	/* credentials (return) */
! 	     struct des_ks_struct *schedule, /* key schedule (return) */
  	     struct sockaddr_in *laddr, /* local address */
  	     struct sockaddr_in *faddr,	/* address of foreign host on fd */
  	     char *version)	/* version string */
--- 103,109 ----
  	     u_int32_t checksum, /* checksum to include in request */
  	     MSG_DAT *msg_data,	/* mutual auth MSG_DAT (return) */
  	     CREDENTIALS *cred,	/* credentials (return) */
! 	     des_key_schedule schedule, /* key schedule (return) */
  	     struct sockaddr_in *laddr, /* local address */
  	     struct sockaddr_in *faddr,	/* address of foreign host on fd */
  	     char *version)	/* version string */
