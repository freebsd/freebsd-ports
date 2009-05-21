*** src/uuid.c.orig	Sun May 17 19:09:00 2009
--- src/uuid.c	Mon May 18 13:43:53 2009
***************
*** 28,34 ****
--- 28,38 ----
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
+ #ifdef __FreeBSD__
+ #include <net/if.h>
+ #else
  #include <linux/if.h>
+ #endif
  #else
  #ifdef _DLL
  #define _WS2TCPIP_H_
***************
*** 133,139 ****
--- 137,147 ----
          strcpy(ifr.ifr_name, IFR->ifr_name);
          if (ioctl(s, SIOCGIFFLAGS, &ifr) == 0) {
              if (! (ifr.ifr_flags & IFF_LOOPBACK)) {
+ #ifdef __FreeBSD__
+ 		if (ioctl(s, SIOCGIFMAC, &ifr) == 0) {
+ #else
                  if (ioctl(s, SIOCGIFHWADDR, &ifr) == 0) {
+ #endif
                      ok = 1;
                      break;
                  }
***************
*** 143,149 ****
--- 151,161 ----
  
      close(s);
      if (ok) {
+ #ifdef __FreeBSD__
+ 	memmove((void *)addr, ifr.ifr_ifru.ifru_addr.sa_data, 6);
+ #else
          memmove((void *)addr, ifr.ifr_hwaddr.sa_data, 6);
+ #endif
      }
      else {
          return -1;
