*** lib/krb/rd_priv.c.orig	Sun Sep 16 17:41:58 2001
--- lib/krb/rd_priv.c	Thu Feb 27 15:14:20 2003
***************
*** 57,63 ****
  
  int32_t
  krb_rd_priv(void *in, u_int32_t in_length, 
! 	    struct des_ks_struct *schedule, des_cblock *key, 
  	    struct sockaddr_in *sender, struct sockaddr_in *receiver, 
  	    MSG_DAT *m_data)
  {
--- 57,63 ----
  
  int32_t
  krb_rd_priv(void *in, u_int32_t in_length, 
! 	    des_key_schedule schedule, des_cblock *key, 
  	    struct sockaddr_in *sender, struct sockaddr_in *receiver, 
  	    MSG_DAT *m_data)
  {
