--- send.cc.orig	2015-07-12 11:10:04 UTC
+++ send.cc
@@ -25,10 +25,12 @@
 
 #include "parallel-gnutls.h"
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/poll.h>
 #include <netinet/in.h>
 #include <netdb.h>
+#include <unistd.h>
 
 #if HAVE_UNISTD_H
 #include <unistd.h>
