*** compface/compface.c	Thu Feb 21 16:42:54 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/compface.c	Wed Jun 19 08:29:12 1991
***************
*** 14,29 ****
   *  to me, then an attempt will be made to fix them.
   */
  
  #include "compface.h"
- #include "vars.h"
  
  int
! compface(char *fbuf)
  {
!     if (!(status = setjmp(comp_env))) {
          ReadFace(fbuf);
          GenFace();
          CompAll(fbuf);
      }
!     return(status);
  }
--- 13,31 ----
   *  to me, then an attempt will be made to fix them.
   */
  
+ #define MAIN
+ 
  #include "compface.h"
  
  int
! compface(fbuf)
! char *fbuf;
  {
! 	if (!(status = setjmp(comp_env)))
! 	{
  		ReadFace(fbuf);
  		GenFace();
  		CompAll(fbuf);
  	}
! 	return status;
  }
