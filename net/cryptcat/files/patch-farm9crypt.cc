--- farm9crypt.cc.orig	Sat Dec 18 05:34:27 2004
+++ farm9crypt.cc	Sun Oct 30 07:45:05 2005
@@ -23,6 +23,7 @@
 #include <sys/types.h>    // suggested by several people -- for OpenBSD, FreeBSD compiles
 #include <sys/socket.h>		/* basics, SO_ and AF_ defs, sockaddr, ... */
 #include <stdlib.h>	
+#include <string.h>
 #else
 #include <fcntl.h>
 #include <io.h>
