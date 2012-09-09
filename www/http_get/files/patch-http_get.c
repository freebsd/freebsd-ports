--- http_get.c.org	2010-06-20 11:20:30.000000000 +0900
+++ http_get.c	2012-09-09 11:24:00.000000000 +0900
@@ -2,7 +2,9 @@
 **
 ** Originally based on a simple version by Al Globus <globus@nas.nasa.gov>.
 ** Debugged and prettified by Jef Poskanzer <jef@mail.acme.com>.  Also includes
-** ifdefs to handle https via OpenSSL.
+** ifdefs to handle https via OpenSSL.  -h argument for debugging multihomed
+** URLs added by Jim Salter.
+**
 */
 
 #include <unistd.h>
@@ -36,6 +38,7 @@
 static int verbose;
 static int timeout;
 static char* url;
+static char* force_host;
 
 /* Protocol symbols. */
 #define PROTO_HTTP 0
@@ -79,6 +82,7 @@
     ncookies = 0;
     header_name = (char*) 0;
     header_value = (char*) 0;
+    force_host = (char*) "[NONE]";
     verbose = 0;
     while ( argn < argc && argv[argn][0] == '-' && argv[argn][1] != '\0' )
 	{
@@ -87,6 +91,11 @@
 	    ++argn;
 	    timeout = atoi( argv[argn] );
 	    }
+    else if ( strcmp( argv[argn], "-H" ) == 0 && argn + 1 < argc )
+        {
+        ++argn;
+        force_host = argv[argn];
+        }
 	else if ( strcmp( argv[argn], "-r" ) == 0 && argn + 1 < argc )
 	    {
 	    ++argn;
@@ -147,7 +156,7 @@
 static void
 usage()
     {
-    (void) fprintf( stderr, "usage:  %s [-c cookie] [-t timeout] [-r referer] [-u user-agent] [-a username:password] [-h header value] [-v] url\n", argv0 );
+    (void) fprintf( stderr, "usage:  %s [-c cookie] [-t timeout] [-H force host address] [-r referer] [-u user-agent] [-a username:password] [-h header value] [-v] url\n", argv0 );
     exit( 1 );
     }
 
@@ -240,7 +249,14 @@
     int i, bytes, b, header_state, status;
 
     (void) alarm( timeout );
-    sockfd = open_client_socket( host, port );
+    if ( strcmp( force_host, "[NONE]" ) == 0 )
+        {
+        sockfd = open_client_socket( host, port );
+        }
+    else
+        {
+        sockfd = open_client_socket( force_host, port );
+        }
 
 #ifdef USE_SSL
     if ( protocol == PROTO_HTTPS )
