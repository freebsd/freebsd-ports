*** src/lock.c.orig	Sat Mar 13 23:39:41 2004
--- src/lock.c	Sat Sep 11 22:05:09 2004
***************
*** 153,159 ****
   */
  
  pid_t
! lock_read (char **file)
  {
    int fd, fallback;
    FILE *fp;
--- 153,159 ----
   */
  
  pid_t
! lock_read (char *file)
  {
    int fd, fallback;
    FILE *fp;
***************
*** 165,175 ****
    fallback = 0;
    do
      {
!       fd = open(*file, O_RDONLY);
        if (-1 == fd)
          {
!           *file = fallback_pid_files [fallback++];
!           if (NULL == *file)
              {
                 /* This makes us depend on procps and coreutils in GNU/Linux
  		* but only coreutils in GNU/Hurd.
--- 165,175 ----
    fallback = 0;
    do
      {
!       fd = open(file, O_RDONLY);
        if (-1 == fd)
          {
!           file = fallback_pid_files [fallback++];
!           if (NULL == file)
              {
                 /* This makes us depend on procps and coreutils in GNU/Linux
  		* but only coreutils in GNU/Hurd.
