--- iiimsf/src/IMAuth.cpp	Sun Jun 20 06:46:28 2004
+++ iiimsf/src/IMAuth.cpp	Wed Feb 16 16:21:47 2005
@@ -47,7 +47,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
