--- src/zm_monitor.cpp.orig	2016-07-28 01:45:26 UTC
+++ src/zm_monitor.cpp
@@ -160,7 +160,7 @@ bool Monitor::MonitorLink::connect()
       return( false );
     }
     mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-    if ( mem_ptr < 0 )
+    if ( mem_ptr < (void *)0 )
     {
       Debug( 3, "Can't shmat link memory: %s", strerror(errno) );
       connected = false;
@@ -194,7 +194,7 @@ bool Monitor::MonitorLink::disconnect()
     connected = false;
 
 #if ZM_MEM_MAPPED
-    if ( mem_ptr > 0 )
+    if ( mem_ptr > (void *)0 )
     {
       msync( mem_ptr, mem_size, MS_ASYNC );
       munmap( mem_ptr, mem_size );
@@ -558,7 +558,7 @@ bool Monitor::connect() {
     exit( -1 );
   }
   mem_ptr = (unsigned char *)shmat( shm_id, 0, 0 );
-  if ( mem_ptr < 0 )
+  if ( mem_ptr < (void *)0 )
   {
     Error( "Can't shmat: %s", strerror(errno));
     exit( -1 );
