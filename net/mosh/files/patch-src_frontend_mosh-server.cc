--- src/frontend/mosh-server.cc.orig	2016-08-10 10:58:28 UTC
+++ src/frontend/mosh-server.cc
@@ -409,7 +409,6 @@ static int run_server( const char *desir
   }
 
   printf( "\nMOSH CONNECT %s %s\n", network->port().c_str(), network->get_key().c_str() );
-  fflush( stdout );
 
   /* don't let signals kill us */
   struct sigaction sa;
@@ -421,25 +420,34 @@ static int run_server( const char *desir
 
 
   /* detach from terminal */
+  fflush( stdout );
+  fflush( stderr );
   pid_t the_pid = fork();
   if ( the_pid < 0 ) {
     perror( "fork" );
   } else if ( the_pid > 0 ) {
-    _exit( 0 );
-  }
+    fprintf( stderr, "\nmosh-server (%s) [build %s]\n", PACKAGE_STRING, BUILD_VERSION );
+    fprintf( stderr, "Copyright 2012 Keith Winstein <mosh-devel@mit.edu>\n" );
+    fprintf( stderr, "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\n" );
 
-  fprintf( stderr, "\nmosh-server (%s) [build %s]\n", PACKAGE_STRING, BUILD_VERSION );
-  fprintf( stderr, "Copyright 2012 Keith Winstein <mosh-devel@mit.edu>\n" );
-  fprintf( stderr, "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\n\n" );
+    fprintf( stderr, "[mosh-server detached, pid = %d]\n", static_cast<int>(the_pid) );
+#ifndef HAVE_IUTF8
+    fprintf( stderr, "\nWarning: termios IUTF8 flag not defined.\nCharacter-erase of multibyte character sequence\nprobably does not work properly on this platform.\n" );
+#endif /* HAVE_IUTF8 */
 
-  fprintf( stderr, "[mosh-server detached, pid = %d]\n", (int)getpid() );
+    fflush( stdout );
+    fflush( stderr );
+    if ( isatty( STDOUT_FILENO ) ) {
+      tcdrain( STDOUT_FILENO );
+    }
+    if ( isatty( STDERR_FILENO ) ) {
+      tcdrain( STDERR_FILENO );
+    }
+    _exit( 0 );
+  }
 
   int master;
 
-#ifndef HAVE_IUTF8
-  fprintf( stderr, "\nWarning: termios IUTF8 flag not defined.\nCharacter-erase of multibyte character sequence\nprobably does not work properly on this platform.\n" );
-#endif /* HAVE_IUTF8 */
-
   /* close file descriptors */
   if ( !verbose ) {
     /* Necessary to properly detach on old versions of sshd (e.g. RHEL/CentOS 5.0). */
