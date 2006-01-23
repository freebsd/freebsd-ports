*** agef.c.orig	Sat Jan 21 22:23:18 2006
--- agef.c	Sat Jan 21 22:23:36 2006
***************
*** 75,86 ****
  unsigned        ages[MAXAGES];	/* age categories */
  int             inodes[MAXAGES];/* inode count */
  long            sizes[MAXAGES];	/* block count */
  
  char            topdir[NAMELEN];/* our starting directory */
! long            today,
!                 time();		/* today's date */
  
  
  
  main(argc, argv)
      int             argc;
--- 75,86 ----
  unsigned        ages[MAXAGES];	/* age categories */
  int             inodes[MAXAGES];/* inode count */
  long            sizes[MAXAGES];	/* block count */
  
  char            topdir[NAMELEN];/* our starting directory */
! long            today;
! time_t          time();		/* today's date */
  
  
  
  main(argc, argv)
      int             argc;
