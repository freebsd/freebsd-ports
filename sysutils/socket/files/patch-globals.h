*** globals.h.orig	Fri Mar 22 11:42:23 2002
--- globals.h	Fri Mar 22 12:05:22 2002
***************
*** 13,19 ****
  # include <sys/param.h>
  #endif
  
- 
  /* globals for socket */
  
  #define IN	0		/* standard input */
--- 13,18 ----
***************
*** 27,35 ****
--- 26,41 ----
  #define A(args) ()
  #endif
  
+ #ifndef USE_INET6
  int create_server_socket A((int port, int queue_length)) ;
  int create_client_socket A((char **hostname, int port)) ;
  int resolve_service A((char *name_or_number, char *protocol, char **name)) ;
+ #else /* USE_INET6 */
+ int *create_server_sockets A((char **port, int queue_length)) ;
+ int create_client_socket A((char **hostname, char **port)) ;
+ int socket_local_name A((int socket, char **name, char **ipname, char **port));
+ int socket_remote_name A((int socket, char **name, char **ipname, char **port));
+ #endif /* USE_INET6 */
  void catchsig A((int sig)) ;
  void usage A((void)) ;
  int do_read_write A((int from, int to)) ;
