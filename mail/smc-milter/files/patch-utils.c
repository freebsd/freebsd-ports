*** utils.c.orig	Thu Mar 10 06:10:48 2005
--- utils.c	Thu Mar 24 11:40:56 2005
***************
*** 32,37 ****
--- 32,41 ----
  	#define MAXLINE	4096
  #endif
  
+ #if !defined O_SYNC && defined O_FSYNC
+ 	#define O_SYNC O_FSYNC
+ #endif
+ 
  typedef struct {
  	char name[PATH_MAX+1];
  	pthread_mutex_t lock;
