*** lib/krb/recvauth.c.orig	Sat Aug 25 21:52:18 2001
--- lib/krb/recvauth.c	Thu Feb 27 15:14:20 2003
***************
*** 108,114 ****
  	     struct sockaddr_in *laddr,	/* local address */
  	     AUTH_DAT *kdata,	/* kerberos data (returned) */
  	     char *filename,	/* name of file with service keys */
! 	     struct des_ks_struct *schedule, /* key schedule (return) */
  	     char *version)	/* version string (filled in) */
  {
      char krb_vers[KRB_SENDAUTH_VLEN + 1]; /* + 1 for the null terminator */
--- 108,114 ----
  	     struct sockaddr_in *laddr,	/* local address */
  	     AUTH_DAT *kdata,	/* kerberos data (returned) */
  	     char *filename,	/* name of file with service keys */
! 	     des_key_schedule schedule, /* key schedule (return) */
  	     char *version)	/* version string (filled in) */
  {
      char krb_vers[KRB_SENDAUTH_VLEN + 1]; /* + 1 for the null terminator */
