diff -c pload.c.orig pload.c
*** pload.c.orig	Tue Feb  1 02:11:24 2000
--- pload.c	Wed Sep 22 13:13:46 2004
***************
*** 596,608 ****
  void do_total(char *b, double total)
  {
  	if (total < 1024.0)
! 		sprintf(b, "%s%0.0f b", b, total);
  	else if (total < (1024.0*1024.0))
! 		sprintf(b, "%s%0.2f k", b, total/1024.0);
  	else if (total < (1024.0*1024.0*1024.0))
! 		sprintf(b, "%s%0.2f M", b, total/1024.0/1024.0);
  	else
! 		sprintf(b, "%s%0.2f G", b, total/1024.0/1024.0/1024.0);
  	
  	return;
  }
--- 596,608 ----
  void do_total(char *b, double total)
  {
  	if (total < 1024.0)
! 		sprintf(b, "%s%0.0f B", b, total);
  	else if (total < (1024.0*1024.0))
! 		sprintf(b, "%s%0.2f kB", b, total/1024.0);
  	else if (total < (1024.0*1024.0*1024.0))
! 		sprintf(b, "%s%0.2f MB", b, total/1024.0/1024.0);
  	else
! 		sprintf(b, "%s%0.2f GB", b, total/1024.0/1024.0/1024.0);
  	
  	return;
  }
***************
*** 610,622 ****
  void do_rate(char *b, double rate)
  {
  	if (rate < 1024.0)
! 		sprintf(b, "%s%0.0f b/s",b, rate);
  	else if (rate < (1024.0*1024.0))
! 		sprintf(b, "%s%0.2f k/s",b, rate/1024.0);
  	else if (rate < (1024.0*1024.0*1024.0))
! 		sprintf(b, "%s%0.2f M/s",b, rate/1024.0/1024.0);
  	else
! 		sprintf(b, "%s%0.2f G/s", b, rate/1024.0/1024.0/1024.0);
  	return;
  }
  
--- 610,622 ----
  void do_rate(char *b, double rate)
  {
  	if (rate < 1024.0)
! 		sprintf(b, "%s%0.0f B/s",b, rate);
  	else if (rate < (1024.0*1024.0))
! 		sprintf(b, "%s%0.2f kB/s",b, rate/1024.0);
  	else if (rate < (1024.0*1024.0*1024.0))
! 		sprintf(b, "%s%0.2f MB/s",b, rate/1024.0/1024.0);
  	else
! 		sprintf(b, "%s%0.2f GB/s", b, rate/1024.0/1024.0/1024.0);
  	return;
  }
  
***************
*** 643,648 ****
--- 643,651 ----
  					break;
  				case 'M':
  					do_rate(buff, max);
+ 					break;
+ 				case 'd':
+ 					sprintf(buff, "%s", resources.device);
  					break;
  				case '%':	/* literal % */
  					i = strlen(buff);
