*** src/http.c.orig	Tue Jun 29 23:59:57 2004
--- src/http.c	Sat Sep 11 22:19:22 2004
***************
*** 27,33 ****
  #include "config.h"
  #endif
  
! #include <alloca.h>
  #include <netdb.h>
  #include <netinet/in.h>
  #include <stdio.h>
--- 27,33 ----
  #include "config.h"
  #endif
  
! #include <sys/types.h>
  #include <netdb.h>
  #include <netinet/in.h>
  #include <stdio.h>
***************
*** 278,284 ****
      + strlen (config->password_key) + strlen (config->password)
      + strlen (config->login_string_footer) + strlen ("Plus approximately 10%");
  
!   temp = (char *) alloca (length);
    if (!temp)
      {
        close (config->sockfd);
--- 278,284 ----
      + strlen (config->password_key) + strlen (config->password)
      + strlen (config->login_string_footer) + strlen ("Plus approximately 10%");
  
!   temp = (char *) malloc(length);
    if (!temp)
      {
        close (config->sockfd);
***************
*** 299,305 ****
  
    DEBUG ("Login string: %s", temp);
  
!   login_string = (char *) alloca (length);
    if (!login_string)
      {
        close (config->sockfd);
--- 299,305 ----
  
    DEBUG ("Login string: %s", temp);
  
!   login_string = (char *) malloc(length);
    if (!login_string)
      {
        close (config->sockfd);
