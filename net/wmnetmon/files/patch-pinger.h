*** pinger.h.orig	Fri Jul 23 17:08:26 1999
--- pinger.h	Sun Apr  1 15:30:20 2001
***************
*** 2,7 ****
--- 2,8 ----
  #define __PINGER_H__
  
  
+ #include <sys/types.h>
  #include <netinet/in.h>
  #include "list.h"
  #include "config.h"
***************
*** 47,54 ****
--- 48,57 ----
  #define UDP_DPORT dest
  #endif
  
+ #ifndef __FreeBSD__
  #if ! (defined(__GLIBC__) && (__GLIBC__ >= 2))
  #define inet_ntoa(x) inet_ntoa(*((struct in_addr *)&(x)))
+ #endif
  #endif
  
  #define TIMEOUT_SIZE 55
