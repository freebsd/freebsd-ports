*** iflib/config.h.orig	Sat Apr 26 04:56:16 1997
--- iflib/config.h	Sun Jun 20 12:52:23 1999
***************
*** 1,6 ****
--- 1,7 ----
  #ifndef _CONFIG_H
  #define _CONFIG_H
  
+ #include <sys/types.h>
  #include "ftn.h"
  
  #ifndef AREA_LIST_TYPE
***************
*** 53,59 ****
  extern area_list *badgroups;
  
  extern long configverbose;
! extern long configtime;
  extern long maxfsize;
  extern long maxpsize;
  extern long maxmsize;
--- 54,60 ----
  extern area_list *badgroups;
  
  extern long configverbose;
! extern time_t configtime;
  extern long maxfsize;
  extern long maxpsize;
  extern long maxmsize;
