*** src/MD4/core3.c.orig	Wed Aug 15 02:02:01 2001
--- src/MD4/core3.c	Sun Dec 17 09:13:36 2006
***************
*** 1575,1581 ****
  
  		  ascii2bin(test, conv, hash);
  		  Decode(result2, hash, 16);
! 		  (unsigned int)bufferr2+=len+35;
  		}
  	      else
  
--- 1575,1581 ----
  
  		  ascii2bin(test, conv, hash);
  		  Decode(result2, hash, 16);
!		  bufferr2=(unsigned int)bufferr2+len+35; 
  		}
  	      else
  
