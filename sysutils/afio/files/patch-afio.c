*** afio.c.orig	Sat Dec 20 17:16:13 2003
--- afio.c	Sat Jan 21 17:31:23 2006
***************
*** 648,658 ****
           daniel.andersson@sto.sema.se  */
        fprintf (stderr, "Media size %ld is less than block size %d\n",
                 aruntil, arbsize);    
  #else
        fprintf (stderr, "Media size %ld is less than block size %d\n",
! 	       (unsigned long) aruntil, arbsize);
  #endif
     usage ();
      }
    if (arpad == 0)
      arpad = arbsize;
--- 648,658 ----
           daniel.andersson@sto.sema.se  */
        fprintf (stderr, "Media size %ld is less than block size %d\n",
                 aruntil, arbsize);    
  #else
        fprintf (stderr, "Media size %ld is less than block size %d\n",
! 	       (u_long) aruntil, arbsize);
  #endif
     usage ();
      }
    if (arpad == 0)
      arpad = arbsize;
***************
*** 3155,3168 ****
  	    return (warn (name, syserr ()));
  	  else
  	    exists = 0;
  	}
  
!       if (mknod (name, asb->sb_mode, asb->sb_rdev) < 0
  	  && (errno != ENOENT
  	      || dirneed (name) < 0
! 	      || mknod (name, asb->sb_mode, asb->sb_rdev) < 0))
  	return (warn (name, syserr ()));
        break;
      case S_IFDIR:
        if (exists)
  	{
--- 3155,3168 ----
  	    return (warn (name, syserr ()));
  	  else
  	    exists = 0;
  	}
  
!       if (mkfifo (name, asb->sb_mode) < 0
  	  && (errno != ENOENT
  	      || dirneed (name) < 0
! 	      || mkfifo (name, asb->sb_mode) < 0))
  	return (warn (name, syserr ()));
        break;
      case S_IFDIR:
        if (exists)
  	{
***************
*** 3194,3204 ****
  		   || dirneed (name) < 0
  		   || mkfifo (name, asb->sb_mode) < 0))
  	return (warn (name, syserr ()));
        break;
  #endif /* S_IFIFO */
! #ifdef	S_IFSOCK
      case S_IFSOCK:
        fd = 0;
        if (exists)
  	if (perm != operm && chmod (name, perm) < 0)
  	  return (warn (name, syserr ()));
--- 3194,3204 ----
  		   || dirneed (name) < 0
  		   || mkfifo (name, asb->sb_mode) < 0))
  	return (warn (name, syserr ()));
        break;
  #endif /* S_IFIFO */
! #ifdef	S_IFSOCK && !defined (__FreeBSD__)
      case S_IFSOCK:
        fd = 0;
        if (exists)
  	if (perm != operm && chmod (name, perm) < 0)
  	  return (warn (name, syserr ()));
