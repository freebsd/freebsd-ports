*** leds.c.orig	Sun Apr  1 15:18:44 2001
--- leds.c	Sun Apr  1 15:19:01 2001
***************
*** 1,5 ****
--- 1,7 ----
  #include <stdlib.h>
+ #ifndef __FreeBSD__
  #include <malloc.h>
+ #endif
  #include <X11/xpm.h>
  #include <stdio.h>
  #include "list.h"
