--- sxmlrpc.c.org	Mon Jul  3 17:28:19 2006
+++ sxmlrpc.c	Mon Aug  6 00:50:08 2007
@@ -442,6 +442,10 @@
 
 /*****************************************************************************/
 
+static sxmlrpc_boolean_t	forever = true;
+
+static void trap(int signo) { forever = false; }
+
 int
 sxmlrpc_server(sxRPC, backlog, callback)
 	sxmlrpc_t *		sxRPC;
@@ -458,9 +462,7 @@
   listenfd = netfd_tcp_server(sxRPC->hostname, sxRPC->servname, backlog);
   if (listenfd != NULL) {
     struct sigaction	act;
-    sxmlrpc_boolean_t	forever = true;
 
-    static void trap(int signo) { forever = false; }
     sigemptyset(&act.sa_mask);
     act.sa_flags	= 0;
     act.sa_handler	= (void *)trap;
