--- src/include/utilities.h.orig
+++ src/include/utilities.h
@@ -54,7 +54,6 @@
 int plp_sleep( int i );
 int Get_max_servers( void );
 int Get_max_fd( void );
-char *Brk_check_size( void );
 char *mystrncat( char *s1, const char *s2, int len );
 char *mystrncpy( char *s1, const char *s2, int len );
 int Get_nonblock_io( int fd );
