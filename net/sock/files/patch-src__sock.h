--- src/sock.h.orig	2010-05-28 00:03:25 UTC
+++ src/sock.h
@@ -62,6 +62,7 @@ extern int errno;
 #define	max(a,b)	((a) > (b) ? (a) : (b))
 
 /* declare global variables */
+extern int		af_46;
 extern int		bindport;
 extern int		broadcast;
 extern int		cbreak;
@@ -114,6 +115,8 @@ extern int		verbose;
 extern int		usewritev;
 
 extern struct sockaddr_in	cliaddr, servaddr;
+extern struct sockaddr_in	cliaddr4, servaddr4;
+extern struct sockaddr_in6	cliaddr6, servaddr6;
 
 /* Earlier versions of gcc under SunOS 4.x have problems passing arguments
    that are structs (as opposed to pointers to structs).  This shows up
@@ -130,7 +133,9 @@ void	buffers(int);
 int     cliopen(char *, char *);
 int	crlf_add(char *, int, const char *, int);
 int	crlf_strip(char *, int, const char *, int);
-void	join_mcast(int, struct sockaddr_in *);
+void	join_mcast_server(int, struct sockaddr_in *, struct sockaddr_in6 *);
+void	join_mcast_client(int, struct sockaddr_in *, struct sockaddr_in6 *,
+			  struct sockaddr_in *, struct sockaddr_in6 *);
 void	loop_tcp(int);
 void	loop_udp(int);
 void	pattern(char *, int);
