--- farm9crypt.cc.orig	2004-12-18 04:34:27 UTC
+++ farm9crypt.cc
@@ -23,6 +23,7 @@
 #include <sys/types.h>    // suggested by several people -- for OpenBSD, FreeBSD compiles
 #include <sys/socket.h>		/* basics, SO_ and AF_ defs, sockaddr, ... */
 #include <stdlib.h>	
+#include <string.h>
 #else
 #include <fcntl.h>
 #include <io.h>
