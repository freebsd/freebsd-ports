*** utils.h.orig	Sun Jan 22 05:13:01 2006
--- utils.h	Sun Jan 22 05:20:11 2006
***************
*** 1,5 ****
--- 1,10 ----
+ #define off64_t off_t
+ #define stat64 stat
+ #define open64 open
+ #define lseek64 lseek
+ 
  void * mymalloc(size_t size, char *what);
  void * myrealloc(void *oldp, size_t newsize, char *what);
  off64_t get_filesize(char *filename);
  int copy_block(int fd_in, int fd_out, off64_t block_size);
  void myseek(int fd, off64_t offset);
