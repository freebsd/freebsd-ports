--- src/zm_stream.cpp.orig	2018-11-07 16:33:47 UTC
+++ src/zm_stream.cpp
@@ -325,7 +325,7 @@ void StreamBase::openComms() {
     strncpy(loc_addr.sun_path, loc_sock_path, sizeof(loc_addr.sun_path));
     loc_addr.sun_family = AF_UNIX;
 		Debug(3, "Binding to %s", loc_sock_path);
-    if ( bind(sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)+1) < 0 ) {
+    if ( ::bind(sd, (struct sockaddr *)&loc_addr, strlen(loc_addr.sun_path)+sizeof(loc_addr.sun_family)+1) < 0 ) {
       Fatal("Can't bind: %s", strerror(errno));
     }
 
