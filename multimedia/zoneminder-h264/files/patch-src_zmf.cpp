--- src/zmf.cpp.orig	2017-05-09 14:54:48 UTC
+++ src/zmf.cpp
@@ -92,7 +92,7 @@ int OpenSocket( int monitor_id )
   strncpy( addr.sun_path, sock_path, sizeof(addr.sun_path) );
   addr.sun_family = AF_UNIX;
 
-  if ( bind( sd, (struct sockaddr *)&addr, strlen(addr.sun_path)+sizeof(addr.sun_family)) < 0 )
+  if ( ::bind( sd, (struct sockaddr *)&addr, strlen(addr.sun_path)+sizeof(addr.sun_family)) < 0 )
   {
     Error( "Can't bind: %s", strerror(errno) );
     exit( -1 );
@@ -331,7 +331,7 @@ int main( int argc, char *argv[] )
     Debug( 1, "Got image, writing to %s", path );
 
     FILE *fd = 0;
-    if ( (fd = fopen( path, "w" )) < 0 )
+    if ( (fd = fopen( path, "w" )) == NULL )
     {
       Error( "Can't fopen '%s': %s", path, strerror(errno) );
       exit( -1 );
