*** src/log.c.orig	Thu Jun 10 21:11:46 2004
--- src/log.c	Sat Sep 11 17:42:44 2004
***************
*** 21,28 ****
  #include "config.h"
  #endif
  
- #include <alloca.h>
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <syslog.h>
--- 21,28 ----
  #include "config.h"
  #endif
  
  #include <stdio.h>
+ #include <stdlib.h>
  #include <stdarg.h>
  #include <string.h>
  #include <syslog.h>
***************
*** 100,106 ****
    char   *str;
    va_list ap;
  
!   str = alloca (MAXDATASIZE);  /* XXX - What is this, a hardcoded value?! */
    va_start (ap, fmt);
    len = vsnprintf (str, MAXDATASIZE, fmt, ap);
    if (len >= 0)
--- 100,106 ----
    char   *str;
    va_list ap;
  
!   str = malloc(MAXDATASIZE);  /* XXX - What is this, a hardcoded value?! */
    va_start (ap, fmt);
    len = vsnprintf (str, MAXDATASIZE, fmt, ap);
    if (len >= 0)
