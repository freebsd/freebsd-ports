*** regex.c.orig	Thu Mar 10 06:10:48 2005
--- regex.c	Wed Mar 23 17:51:06 2005
***************
*** 58,64 ****
  # include <wctype.h>
  #endif
  
! #include <malloc.h>
  #include "regex.h"
  
  /* This is for multi byte string support.  */
--- 58,64 ----
  # include <wctype.h>
  #endif
  
! #include <stdlib.h>
  #include "regex.h"
  
  /* This is for multi byte string support.  */
***************
*** 148,159 ****
--- 148,161 ----
     even if config.h says that we can.  */
  # undef REL_ALLOC
  
+ #ifndef _STDLIB_H_
  # if defined STDC_HEADERS || defined _LIBC
  #  include <stdlib.h>
  # else
  char *malloc ();
  char *realloc ();
  # endif
+ #endif /* _STDLIB_H_ */
  
  /* When used in Emacs's lib-src, we need to get bzero and bcopy somehow.
     If nothing else has been done, use the method below.  */
