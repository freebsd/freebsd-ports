*** lib/krb/krb-protos.h.orig	Sat Aug 25 20:46:51 2001
--- lib/krb/krb-protos.h	Thu Feb 27 15:14:20 2003
***************
*** 177,183 ****
  	u_int32_t checksum,
  	MSG_DAT *msg_data,
  	des_cblock *session,
! 	struct des_ks_struct *schedule,
  	struct sockaddr_in *laddr,
  	struct sockaddr_in *faddr));
  
--- 177,183 ----
  	u_int32_t checksum,
  	MSG_DAT *msg_data,
  	des_cblock *session,
! 	des_key_schedule schedule,
  	struct sockaddr_in *laddr,
  	struct sockaddr_in *faddr));
  
***************
*** 457,463 ****
  	void *in,
  	void *out,
  	u_int32_t length,
! 	struct des_ks_struct *schedule,
  	des_cblock *key,
  	struct sockaddr_in *sender,
  	struct sockaddr_in *receiver));
--- 457,463 ----
  	void *in,
  	void *out,
  	u_int32_t length,
! 	des_key_schedule schedule,
  	des_cblock *key,
  	struct sockaddr_in *sender,
  	struct sockaddr_in *receiver));
***************
*** 540,546 ****
  krb_rd_priv __P((
  	void *in,
  	u_int32_t in_length,
! 	struct des_ks_struct *schedule,
  	des_cblock *key,
  	struct sockaddr_in *sender,
  	struct sockaddr_in *receiver,
--- 540,546 ----
  krb_rd_priv __P((
  	void *in,
  	u_int32_t in_length,
! 	des_key_schedule schedule,
  	des_cblock *key,
  	struct sockaddr_in *sender,
  	struct sockaddr_in *receiver,
***************
*** 583,589 ****
  	struct sockaddr_in *laddr,
  	AUTH_DAT *kdata,
  	char *filename,
! 	struct des_ks_struct *schedule,
  	char *version));
  
  int KRB_LIB_FUNCTION
--- 583,589 ----
  	struct sockaddr_in *laddr,
  	AUTH_DAT *kdata,
  	char *filename,
! 	des_key_schedule schedule,
  	char *version));
  
  int KRB_LIB_FUNCTION
***************
*** 597,603 ****
  	u_int32_t checksum,
  	MSG_DAT *msg_data,
  	CREDENTIALS *cred,
! 	struct des_ks_struct *schedule,
  	struct sockaddr_in *laddr,
  	struct sockaddr_in *faddr,
  	char *version));
--- 597,603 ----
  	u_int32_t checksum,
  	MSG_DAT *msg_data,
  	CREDENTIALS *cred,
! 	des_key_schedule schedule,
  	struct sockaddr_in *laddr,
  	struct sockaddr_in *faddr,
  	char *version));
