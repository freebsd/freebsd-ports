*** SRC/sp_coletree.c.orig	Fri Aug  6 05:31:22 1999
--- SRC/sp_coletree.c	Thu Dec 16 03:29:12 1999
***************
*** 2,8 ****
--- 2,10 ----
  /*  Elimination tree computation and layout routines */
  
  #include <stdio.h>
+ #ifndef __STDC__
  #include <malloc.h>
+ #endif
  #include <stdlib.h>
  #include "util.h"
  
