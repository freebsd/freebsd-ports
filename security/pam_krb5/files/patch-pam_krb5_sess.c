*** pam_krb5_sess.c.orig	Sat Sep  7 10:42:40 2002
--- pam_krb5_sess.c	Sat Sep  7 10:43:02 2002
***************
*** 9,14 ****
--- 9,15 ----
  static const char rcsid[] = "$Id: pam_krb5_sess.c,v 1.1.1.1.2.5 2001/09/24 14:58:15 nectar Exp $";
  
  #include <krb5.h>
+ #include <syslog.h>
  #include "pam_krb5.h"
  
  /* Initiate session management */
