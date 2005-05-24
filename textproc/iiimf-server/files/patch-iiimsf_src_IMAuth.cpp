--- iiimsf/src/IMAuth.cpp.orig	Mon May  9 18:08:19 2005
+++ iiimsf/src/IMAuth.cpp	Mon May  9 18:08:53 2005
@@ -47,7 +47,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
