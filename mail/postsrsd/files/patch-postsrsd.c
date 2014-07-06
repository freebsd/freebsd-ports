--- postsrsd.c	2014-01-03 01:01:47.000000000 +0100
+++ postsrsd.c.new	2014-06-18 23:31:33.290651741 +0200
@@ -28,7 +28,7 @@
 #include <pwd.h>
 #include <string.h>
 #include <poll.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <syslog.h>
 
 #ifndef VERSION
@@ -47,7 +47,7 @@
   memset (&hints, 0, sizeof(hints));
   hints.ai_family = family;
   hints.ai_socktype = SOCK_STREAM;
-  hints.ai_flags = AI_ADDRCONFIG | AI_V4MAPPED;
+  hints.ai_flags = AI_ADDRCONFIG;
   err = getaddrinfo(NULL, service, &hints, &addr);
   if (err != 0) {
     fprintf(stderr, "%s: bind_service(%s): %s\n", self, service, gai_strerror(err));
