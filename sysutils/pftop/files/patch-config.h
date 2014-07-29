*** config.h.orig	Sat Jan 21 04:39:55 2006
--- config.h	Sat Jan 21 04:40:15 2006
***************
*** 23,31 ****
  
  #if OS_LEVEL > 32
  #define HAVE_ADDR_MASK
  #define HAVE_ADDR_TYPE
! #define HAVE_ALTQ
  #define HAVE_RULE_TOS
  #define HAVE_OP_RRG
  #endif
  
--- 23,31 ----
  
  #if OS_LEVEL > 32
  #define HAVE_ADDR_MASK
  #define HAVE_ADDR_TYPE
! /* #define HAVE_ALTQ */
  #define HAVE_RULE_TOS
  #define HAVE_OP_RRG
  #endif
  
