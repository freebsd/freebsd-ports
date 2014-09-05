--- nepenthes-core/src/Socket.cpp.orig
+++ nepenthes-core/src/Socket.cpp
@@ -27,10 +27,13 @@
 
 /* $Id: Socket.cpp 699 2006-11-11 09:20:15Z common $ */
 
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
 #include <string>
 #include <sstream>
 
-#include <time.h>
+#include <ctime>
 
 #include <sys/types.h>
 #include <sys/socket.h>
