--- http_get.c.orig	Wed Dec 15 19:10:11 2004
+++ http_get.c	Wed Dec 15 19:10:30 2004
@@ -2,7 +2,9 @@
 **
 ** Originally based on a simple version by Al Globus <globus@nas.nasa.gov>.
 ** Debugged and prettified by Jef Poskanzer <jef@acme.com>.  Also includes
-** ifdefs to handle https via OpenSSL.
+** ifdefs to handle https via OpenSSL.  -h argument for debugging multihomed
+** URLs added by Jim Salter.
+**
 */
 
 #include <unistd.h>
@@ -35,6 +37,7 @@
 static int verbose;
 static int timeout;
 static char* url;
+static char* force_host;
 
 /* Protocol symbols. */
 #define PROTO_HTTP 0
@@ -72,6 +75,8 @@
     user_agent = "http_get";
     auth_token = (char*) 0;
     cookie = (char*) 0;
+    force_host = (char*) "[NONE]";
+
     while ( argn < argc && argv[argn][0] == '-' && argv[argn][1] != '\0' )
 	{
 	if ( strcmp( argv[argn], "-v" ) == 0 )
@@ -81,6 +86,11 @@
 	    ++argn;
 	    timeout = atoi( argv[argn] );
 	    }
+        else if ( strcmp( argv[argn], "-h" ) == 0 && argn + 1 < argc )
+            {
+            ++argn;
+            force_host = argv[argn];
+            }
 	else if ( strcmp( argv[argn], "-r" ) == 0 && argn + 1 < argc )
 	    {
 	    ++argn;
@@ -127,7 +137,7 @@
 static void
 usage()
     {
-    (void) fprintf( stderr, "usage:  %s [-t timeout] [-r referer] [-u user-agent] [-a username:password] url\n", argv0 );
+    (void) fprintf( stderr, "usage:  %s [-t timeout] [-h force host address] [-r referer] [-u user-agent] [-a username:password] url\n", argv0 );
     exit( 1 );
     }
 
@@ -218,7 +228,16 @@
     int bytes, b, header_state, status;
 
     (void) alarm( timeout );
-    sockfd = open_client_socket( host, port );
+
+if ( force_host == "[NONE]" )
+    {
+        sockfd = open_client_socket( host, port );
+    }
+else
+    {
+        sockfd = open_client_socket( force_host, port );
+    }
+
 
 #ifdef USE_SSL
     if ( protocol == PROTO_HTTPS )
