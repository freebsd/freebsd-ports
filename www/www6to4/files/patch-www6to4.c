*** www6to4.c.orig	Fri Mar 22 00:25:51 2002
--- www6to4.c	Fri Mar 22 00:26:48 2002
***************
*** 59,65 ****
  char *patterns[MAXPATTERNS];
  int lastpattern = -1;
  
! char *default_configfile = "/etc/www6to4.conf";
  char *configfile = NULL;
  char *forwardfile = NULL;
  int debug = 0;
--- 59,65 ----
  char *patterns[MAXPATTERNS];
  int lastpattern = -1;
  
! char *default_configfile = "/usr/local/etc/www6to4/www6to4.conf";
  char *configfile = NULL;
  char *forwardfile = NULL;
  int debug = 0;
