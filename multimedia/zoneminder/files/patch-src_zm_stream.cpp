--- src/zm_stream.cpp.orig 2009-05-08 16:47:27.000000000 +0300
+++ src/zm_stream.cpp	   2011-05-31 12:53:35.182245374 +0300
@@ -289,7 +289,7 @@
 
         strncpy( loc_addr.sun_path, loc_sock_path, sizeof(loc_addr.sun_path) );
         loc_addr.sun_family = AF_UNIX;
-        if ( bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)) < 0 )
+        if ( bind( sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path) + 1 +sizeof(loc_addr.sun_family)) < 0 )
         {
             Fatal( "Can't bind: %s", strerror(errno) );
         }
