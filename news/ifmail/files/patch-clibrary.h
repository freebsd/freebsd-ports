*** iflib/clibrary.h	Sat Sep 11 17:16:11 1993
--- iflib/clibrary.h.neu	Wed Feb 19 20:53:56 1997
***************
*** 121,128 ****
--- 121,130 ----
  extern void	exit();
  /* =()<extern @<GETPIDVAL>@	getpid();>()= */
  extern int	getpid();
+ #ifndef __FreeBSD__
  /* =()<extern @<LSEEKVAL>@	lseek();>()= */
  extern long	lseek();
+ #endif
  /* =()<extern @<QSORTVAL>@	qsort();>()= */
  extern int	qsort();
  /* =()<extern @<SLEEPVAL>@	sleep();>()= */
