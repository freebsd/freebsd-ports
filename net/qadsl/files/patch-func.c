*** func.c.orig	Thu Dec 13 21:45:53 2001
--- func.c	Thu Dec 13 21:47:55 2001
***************
*** 48,53 ****
  
  void usage(char *argv) {
  	printf("Usage: %s [ -h ] [ -c file ] [ -l ] [ -o ]\n", argv);
! 	printf("\t-h\t\tPrint this message\n\t-c file\t\tUse settings from file instead of /etc/qadsl.conf\n\t"
  		"-l\t\tWill try to login\n\t-o\t\tWill try to logout\n");
  }
--- 48,53 ----
  
  void usage(char *argv) {
  	printf("Usage: %s [ -h ] [ -c file ] [ -l ] [ -o ]\n", argv);
! 	printf("\t-h\t\tPrint this message\n\t-c file\t\tUse settings from file instead of " CONF "\n\t"
  		"-l\t\tWill try to login\n\t-o\t\tWill try to logout\n");
  }
