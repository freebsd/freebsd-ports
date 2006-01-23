*** io.c.orig	Sun Jan 22 05:18:41 2006
--- io.c	Sun Jan 22 05:18:54 2006
***************
*** 9,18 ****
--- 9,19 ----
  #include <sys/stat.h>
  
  #include "io.h"
  #include "error.h"
  #include "gen.h"
+ #include "utils.h"
  
  ssize_t READ(int fd, char *whereto, size_t len)
  {
  	ssize_t cnt=0;
  
