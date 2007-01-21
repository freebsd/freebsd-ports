*** src/MD5/global.h.orig	Wed Aug 15 05:55:31 2001
--- src/MD5/global.h	Sun Dec 17 09:20:01 2006
***************
*** 1,3 ****
--- 1,4 ----
+ #include <stdlib.h>
  #ifdef ISBIG_ENDIAN
  extern unsigned int x1[14];
  #else
