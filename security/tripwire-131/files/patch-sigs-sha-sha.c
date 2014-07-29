This patch eliminates a compiler warning about LITTLE_ENDIAN begin
redefined.

*** sigs/sha/sha.c.orig	Mon Jul 25 08:46:45 1994
--- sigs/sha/sha.c	Mon Mar 31 19:55:23 1997
***************
*** 47,52 ****
--- 47,54 ----
  #include "sha.h"
  
  #if BYTEORDER == 0x1234
+ #undef BIG_ENDIAN
+ #undef LITTLE_ENDIAN
  #define LITTLE_ENDIAN
  #endif
  
