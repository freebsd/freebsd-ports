--- netmap/lookup.c.orig	2010-01-06 07:59:38.000000000 +0900
+++ netmap/lookup.c	2011-11-23 22:32:15.000000000 +0900
@@ -1,6 +1,7 @@
-#include <strstream>
 #include <iostream>
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netdb.h> 	//hostent def
 
 //from belgolib
