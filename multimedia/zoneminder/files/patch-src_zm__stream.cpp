--- src/zm_stream.cpp.orig	2018-02-23 20:55:30 UTC
+++ src/zm_stream.cpp
@@ -332,7 +332,7 @@ void StreamBase::openComms()
 
     strncpy( loc_addr.sun_path, loc_sock_path, sizeof(loc_addr.sun_path) );
     loc_addr.sun_family = AF_UNIX;
-    if ( bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)+1 ) < 0 )
+    if ( ::bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)+1 ) < 0 ) //picks wrong bind without ::
     {
       Fatal( "Can't bind: %s", strerror(errno) );
     }
