
$FreeBSD$

--- gmetad/gmetad.c.orig	Mon Dec  9 14:43:23 2002
+++ gmetad/gmetad.c	Fri Feb 21 11:52:24 2003
@@ -40,7 +40,7 @@
 pthread_mutex_t  server_socket_mutex     = PTHREAD_MUTEX_INITIALIZER;
 int server_threads = 2;
 char *rrd_rootdir =  "/var/lib/ganglia/rrds";
-char *setuid_username = "nobody";
+char *setuid_username = "ganglia";
 int should_setuid = 1;
 unsigned int source_index = 0;
 
