*** appl/bsd/encrypt.c.orig	Sun Sep  9 15:27:22 2001
--- appl/bsd/encrypt.c	Thu Feb 27 15:20:00 2003
***************
*** 68,74 ****
  int LEFT_JUSTIFIED = 0;
  
  int
! bsd_des_enc_read(int fd, char *buf, int len, struct des_ks_struct *sched, des_cblock *iv)
  {
    /* data to be unencrypted */
    int net_num=0;
--- 68,74 ----
  int LEFT_JUSTIFIED = 0;
  
  int
! bsd_des_enc_read(int fd, char *buf, int len, des_key_schedule sched, des_cblock *iv)
  {
    /* data to be unencrypted */
    int net_num=0;
***************
*** 213,219 ****
  }
  
  int
! bsd_des_enc_write(int fd, char *buf, int len, struct des_ks_struct *sched, des_cblock *iv)
  {
    long rnum;
    int i,j,k,outnum;
--- 213,219 ----
  }
  
  int
! bsd_des_enc_write(int fd, char *buf, int len, des_key_schedule sched, des_cblock *iv)
  {
    long rnum;
    int i,j,k,outnum;
