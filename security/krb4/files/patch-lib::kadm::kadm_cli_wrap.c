*** lib/kadm/kadm_cli_wrap.c.orig	Thu Aug 15 06:31:37 2002
--- lib/kadm/kadm_cli_wrap.c	Thu Feb 27 15:14:20 2003
***************
*** 138,144 ****
  /* takes in the sess_key and key_schedule and sets them appropriately */
  static int
  kadm_cli_keyd(des_cblock (*s_k), /* session key */
! 	      struct des_ks_struct *s_s) /* session key schedule */
  {
  	CREDENTIALS cred;	       /* to get key data */
  	int stat;
--- 138,144 ----
  /* takes in the sess_key and key_schedule and sets them appropriately */
  static int
  kadm_cli_keyd(des_cblock (*s_k), /* session key */
! 	      des_key_schedule s_s) /* session key schedule */
  {
  	CREDENTIALS cred;	       /* to get key data */
  	int stat;
