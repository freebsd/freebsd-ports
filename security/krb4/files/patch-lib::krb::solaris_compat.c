*** lib/krb/solaris_compat.c.orig	Thu Dec  2 10:58:44 1999
--- lib/krb/solaris_compat.c	Thu Feb 27 15:14:20 2003
***************
*** 42,48 ****
  
  int32_t
  _C0095C2A(void *in, void *out, u_int32_t length, 
! 	  struct des_ks_struct *schedule, des_cblock *key, 
  	  struct sockaddr_in *sender, struct sockaddr_in *receiver)
  {
      return krb_mk_priv (in, out, length, schedule, key, sender, receiver);
--- 42,48 ----
  
  int32_t
  _C0095C2A(void *in, void *out, u_int32_t length, 
! 	  des_key_schedule schedule, des_cblock *key, 
  	  struct sockaddr_in *sender, struct sockaddr_in *receiver)
  {
      return krb_mk_priv (in, out, length, schedule, key, sender, receiver);
***************
*** 50,56 ****
  
  int32_t
  _C0095C2B(void *in, u_int32_t in_length, 
! 	  struct des_ks_struct *schedule, des_cblock *key, 
  	  struct sockaddr_in *sender, struct sockaddr_in *receiver, 
  	  MSG_DAT *m_data)
  {
--- 50,56 ----
  
  int32_t
  _C0095C2B(void *in, u_int32_t in_length, 
! 	  des_key_schedule schedule, des_cblock *key, 
  	  struct sockaddr_in *sender, struct sockaddr_in *receiver, 
  	  MSG_DAT *m_data)
  {
