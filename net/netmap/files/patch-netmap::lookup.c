--- netmap/lookup.c.orig	Sun Feb 10 02:57:26 2002
+++ netmap/lookup.c	Sun Feb 10 02:59:22 2002
@@ -1,6 +1,8 @@
 #include <strstream>
 #include <iostream>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h> 	//hostent def
 
 //from belgolib
