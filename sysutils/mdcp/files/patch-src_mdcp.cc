--- src/mdcp.cc.orig	2008-04-13 14:51:16 UTC
+++ src/mdcp.cc
@@ -136,7 +136,7 @@ void *readFile( void * )
   pthread_mutex_unlock( &buffer.lock[nb] );
 
   buffer.used[nb] = read( arqIn, buffer.buff[nb], buffer.len );
-  if( buffer.used < 0 )
+  if( buffer.used[nb] < 0 )
   {
     buffer.used[nb] = 0;
     end = true;
