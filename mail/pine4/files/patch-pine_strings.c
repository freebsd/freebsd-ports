*** pine/strings.c.orig	Thu May  6 10:47:29 2004
--- pine/strings.c	Wed Jun  9 04:16:00 2004
***************
*** 3754,3760 ****
  		p = ct->table = (unsigned char *)
  		  fs_get(256 * sizeof(unsigned char));
  		for(i = 0; i < 256; i++){
! 		    unsigned char fc;
  		    p[i] = '?';
  		    switch(from->type){	/* get "from" UCS-2 codepoint */
  		    case CT_1BYTE0:	/* ISO 8859-1 */
--- 3754,3760 ----
  		p = ct->table = (unsigned char *)
  		  fs_get(256 * sizeof(unsigned char));
  		for(i = 0; i < 256; i++){
! 		    unsigned int fc;
  		    p[i] = '?';
  		    switch(from->type){	/* get "from" UCS-2 codepoint */
  		    case CT_1BYTE0:	/* ISO 8859-1 */
***************
*** 3789,3795 ****
  			}
  			break;
  		    }
- 		    p[i] = i;
  		}
  		break;
  	    }
--- 3789,3794 ----
