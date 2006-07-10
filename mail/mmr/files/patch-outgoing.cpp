--- outgoing.cpp.orig	Mon Jan 23 17:55:34 2006
+++ outgoing.cpp	Mon Jul 10 01:14:23 2006
@@ -16,7 +16,9 @@
 #include "tempfile.h"
 #include "outgoing.h"
 
+#ifndef MAILER
 #define MAILER	"/usr/lib/sendmail -t"
+#endif
 #define EDITOR	"vi +%d"
 #define SIGFILE	".signature"
 
