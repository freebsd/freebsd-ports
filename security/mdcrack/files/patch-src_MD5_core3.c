*** src/MD5/core3.c.orig	Wed Aug 15 01:59:05 2001
--- src/MD5/core3.c	Sun Dec 17 09:16:57 2006
***************
*** 1537,1543 ****
  
  		  ascii2bin(test, conv, hash);
  		  Decode(result2, hash, 16);
! 		  (unsigned int)bufferr2+=len+35;
  		}
  	      else
  
--- 1537,1543 ----
  
  		  ascii2bin(test, conv, hash);
  		  Decode(result2, hash, 16);
! 		  bufferr2=(unsigned int)bufferr2+len+35;
  		}
  	      else
  
