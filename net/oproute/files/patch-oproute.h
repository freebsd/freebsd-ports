--- oproute.h.orig	Thu Mar  1 10:28:31 2001
+++ oproute.h	Sat Mar  3 23:12:12 2001
@@ -3,6 +3,9 @@
 
 #include <vector>
 #include <string>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/time.h>
 #include <map>
 
