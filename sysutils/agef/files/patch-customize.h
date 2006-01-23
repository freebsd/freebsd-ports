*** customize.h.orig	Sat Jan 21 22:22:14 2006
--- customize.h	Sat Jan 21 22:24:41 2006
***************
*** 7,22 ****
  */
  
  #define FLOAT_FORMAT	"%d %#4.1fM"	/* if your printf does %# */
  /*#define FLOAT_FORMAT	"%d %4.1fM" /* if it doesn't do %# */
  
! #define NAMELEN	512		/* max size of a full pathname */
  
  #ifdef BSD
! #	include		<sys/dir.h>
  #	define	OPEN	DIR
! #	define	READ	struct direct
  #	define	NAME(x)	((x).d_name)
  #else
  #ifdef SYS_V
   /* Customize this.  This is part of Doug Gwyn's package for */
   /* reading directories.  If you've put this file somewhere */
--- 7,22 ----
  */
  
  #define FLOAT_FORMAT	"%d %#4.1fM"	/* if your printf does %# */
  /*#define FLOAT_FORMAT	"%d %4.1fM" /* if it doesn't do %# */
  
! #define NAMELEN	1024		/* max size of a full pathname */
  
  #ifdef BSD
! #	include		<dirent.h>
  #	define	OPEN	DIR
! #	define	READ	struct dirent
  #	define	NAME(x)	((x).d_name)
  #else
  #ifdef SYS_V
   /* Customize this.  This is part of Doug Gwyn's package for */
   /* reading directories.  If you've put this file somewhere */
