--- xinetd/child.c.orig	2016-07-13 19:00:31 UTC
+++ xinetd/child.c
@@ -168,7 +168,8 @@ void exec_server( const struct server *s
    }
 #endif
 
-   (void) Sclose( descriptor ) ;
+   if ( descriptor > MAX_PASS_FD )
+      (void) Sclose( descriptor ) ;
 
 #ifndef solaris
 #if !defined(HAVE_SETSID)
@@ -321,11 +322,6 @@ void child_process( struct server *serp 
    signals_pending[0] = -1;
    signals_pending[1] = -1;
 
-   Sclose(0);
-   Sclose(1);
-   Sclose(2);
-
-
 #ifdef DEBUG_SERVER
    if ( debug.on )
    {
