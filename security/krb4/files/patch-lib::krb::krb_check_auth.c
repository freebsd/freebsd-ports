*** lib/krb/krb_check_auth.c.orig	Thu Dec  2 10:58:42 1999
--- lib/krb/krb_check_auth.c	Thu Feb 27 15:14:20 2003
***************
*** 50,56 ****
  	       u_int32_t checksum,
  	       MSG_DAT *msg_data,
  	       des_cblock *session,
! 	       struct des_ks_struct *schedule,
  	       struct sockaddr_in *laddr,
  	       struct sockaddr_in *faddr)
  {
--- 50,56 ----
  	       u_int32_t checksum,
  	       MSG_DAT *msg_data,
  	       des_cblock *session,
! 	       des_key_schedule schedule,
  	       struct sockaddr_in *laddr,
  	       struct sockaddr_in *faddr)
  {
