*** compface/uncompface.c	Thu Feb 21 16:42:54 2002
--- /home/lkoeller/tmp/ports/mail/faces/work/faces/compface/uncompface.c	Wed Jun 19 08:29:14 1991
***************
*** 14,29 ****
   *  to me, then an attempt will be made to fix them.
   */
  
  #include "compface.h"
- #include "vars.h"
  
  int
! uncompface(char *fbuf)
  {
!     if (!(status = setjmp(comp_env))) {
!         UnCompAll(fbuf);       /* compress otherwise */
          UnGenFace();
          WriteFace(fbuf);
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
! uncompface(fbuf)
! char *fbuf;
  {
! 	if (!(status = setjmp(comp_env)))
! 	{
! 		UnCompAll(fbuf);/* compress otherwise */
  		UnGenFace();
  		WriteFace(fbuf);
  	}
! 	return status;
  }
