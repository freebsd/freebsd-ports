*** lib/krb/mk_priv.c.orig	Sun Sep 16 17:41:58 2001
--- lib/krb/mk_priv.c	Thu Feb 27 15:14:20 2003
***************
*** 78,84 ****
  
  int32_t
  krb_mk_priv(void *in, void *out, u_int32_t length, 
! 	    struct des_ks_struct *schedule, des_cblock *key, 
  	    struct sockaddr_in *sender, struct sockaddr_in *receiver)
  {
      unsigned char *p = (unsigned char*)out;
--- 78,84 ----
  
  int32_t
  krb_mk_priv(void *in, void *out, u_int32_t length, 
! 	    des_key_schedule schedule, des_cblock *key, 
  	    struct sockaddr_in *sender, struct sockaddr_in *receiver)
  {
      unsigned char *p = (unsigned char*)out;
