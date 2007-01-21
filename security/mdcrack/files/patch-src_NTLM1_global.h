*** src/NTLM1/global.h.orig	Wed Jan 17 17:24:41 2007
--- src/NTLM1/global.h	Wed Jan 17 17:25:02 2007
***************
*** 1,3 ****
--- 1,6 ----
+ #include <stdlib.h>
+ #include <string.h>
+ 
  #ifdef ISBIG_ENDIAN
  extern unsigned int x1[14];
  #else
