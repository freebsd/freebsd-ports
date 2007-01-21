*** src/MD4/global.h.orig	Wed Aug 15 02:03:40 2001
--- src/MD4/global.h	Sun Dec 17 09:19:58 2006
***************
*** 1,3 ****
--- 1,4 ----
+ #include <stdlib.h>
  #ifdef ISBIG_ENDIAN
  extern unsigned int x1[14];
  #else
