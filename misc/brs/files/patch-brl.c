*** brl.c.orig	Tue Apr 12 19:31:59 1994
--- brl.c	Thu Jul 10 23:06:55 2003
***************
*** 1146,1152 ****
      if (dfname == NULL)
  	dfname = "bible.data";
      if (dfpath == NULL)
! 	dfpath = "./ /usr/local/lib/";
      tsl_init( dfname, dfpath, memlimit );
  
      /* Set (low) illegal value for current context.
--- 1146,1152 ----
      if (dfname == NULL)
  	dfname = "bible.data";
      if (dfpath == NULL)
! 	dfpath = "./ %%PREFIX%%/share/brs/";
      tsl_init( dfname, dfpath, memlimit );
  
      /* Set (low) illegal value for current context.
