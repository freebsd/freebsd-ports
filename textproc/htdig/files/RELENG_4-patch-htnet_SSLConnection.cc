--- htnet/SSLConnection.cc.orig	Mon Jul 21 01:16:11 2003
+++ htnet/SSLConnection.cc	Fri Mar 19 00:57:38 2004
@@ -29,6 +29,10 @@
 #include <iostream.h>
 #endif /* HAVE_STD */
 
+#include <sys/types.h>
+#include <sys/time.h>
+#include <unistd.h>
+
 // Global needed only once in HtDig
 //
 SSL_CTX *SSLConnection::ctx = NULL;
