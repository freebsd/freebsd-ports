*** tsl.c.orig	Wed Aug  9 19:47:29 1995
--- tsl.c	Fri Nov 21 17:31:35 2003
***************
*** 106,112 ****
  \*----------------------------------------------------------------------*/
  
  #include <stdio.h>
! #include <varargs.h>
  #include "tsl.h"
  
  
--- 106,112 ----
  \*----------------------------------------------------------------------*/
  
  #include <stdio.h>
! #include <stdarg.h>
  #include "tsl.h"
  
  
***************
*** 155,161 ****
  
  
  
! tsl_error( fatal, va_alist )
  /*----------------------------------------------------------------------
  |   NAME:
  |       tsl_error
--- 155,161 ----
  
  
  
! tsl_error( int fatal, ... )
  /*----------------------------------------------------------------------
  |   NAME:
  |       tsl_error
***************
*** 172,184 ****
  |
  \*----------------------------------------------------------------------*/
  
- int fatal;
- va_dcl
  {
      va_list ap;
      char *format;
  
!     va_start(ap);
  
      format = va_arg(ap, char *);
      vfprintf(stderr, format, ap);
--- 172,182 ----
  |
  \*----------------------------------------------------------------------*/
  
  {
      va_list ap;
      char *format;
  
!     va_start(ap, fatal);
  
      format = va_arg(ap, char *);
      vfprintf(stderr, format, ap);
