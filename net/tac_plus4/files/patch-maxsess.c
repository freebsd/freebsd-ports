Using tacacs I found that ckfinger() function from maxsess.c module
returns wrong count of current sessions for users with "maxsess"
parameter established in tac_plus.conf. It happens if Cisco access 
server works with IOS v 12.x.
On the other hand ckfinger() works well with IOS v 11.x

Here are patches for both maxsess.c and port's Makefile to fix 
this problem (but it is just workaround, ckfinger() should be 
fully rewritten).

Best regards,
Sergey E. Levov (serg@informika.ru)

*** maxsess.c.orig	Fri Jan 19 17:16:46 2001
--- maxsess.c	Fri Jan 19 17:25:51 2001
***************
*** 470,476 ****
--- 470,480 ----
  	}
  	/* Extract username, up to 10 chars wide, starting at char 13 */
  	nmlen = 0;
+ #if (TAC_IOS_VERSION == 11)
  	name = p + 13;
+ #else
+ 	name = p + 15;
+ #endif		
  	for (i = 0; *name && !isspace(*name) && (i < 10); i++) {
  	    nmbuf[nmlen++] = *name++;
  	}
