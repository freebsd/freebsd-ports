--- src/XmlRpcDispatch.cpp.orig	Sun Jan 25 23:10:04 2004
+++ src/XmlRpcDispatch.cpp	Sun Jan 25 23:10:36 2004
@@ -6,6 +6,10 @@
 #include <math.h>
 #include <sys/timeb.h>
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+
 #if defined(_WINDOWS)
 # include <winsock2.h>
 
