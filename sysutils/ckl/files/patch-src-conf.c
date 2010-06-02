*** src/conf.c.orig	Sun Jan 24 02:46:27 2010
--- src/conf.c		Tue Jun  1 07:19:59 2010
***************
*** 86,96 ****
  {
    int rv;
    FILE *fp;
    
    /* TODO: respect prefix */
!   fp = fopen("/etc/cloudkick.conf", "r");
    if (fp == NULL) {
      char buf[2048];
      const char *home = getenv("HOME");
      
      if (home == NULL) {
--- 86,96 ----
  {
    int rv;
    FILE *fp;
    
    /* TODO: respect prefix */
!   fp = fopen("/usr/local/etc/cloudkick.conf", "r");
    if (fp == NULL) {
      char buf[2048];
      const char *home = getenv("HOME");
      
      if (home == NULL) {
