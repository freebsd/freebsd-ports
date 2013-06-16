diff -c ./printit.c ../../m/printit.c
*** ./printit.c	Sat Jun  9 12:32:26 1990
--- ../../m/printit.c	Thu Feb 10 07:08:42 1994
***************
*** 27,33 ****
  STATIC int printable();
  
  /* in practice, even the longest paths are < 100 bytes */
! #define PATHSIZE 512
  
  void
  printit()
--- 27,36 ----
  STATIC int printable();
  
  /* in practice, even the longest paths are < 100 bytes */
! /* Dirk meyer 10.02.94 */
! /* in reality we have reached paths up to 200 bytes */
! /* the path must fit two times in the buffer */
! #define PATHSIZE 4096
  
  void
  printit()
