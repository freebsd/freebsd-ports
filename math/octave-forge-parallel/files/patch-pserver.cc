--- pserver.cc.orig	2015-07-12 11:10:04 UTC
+++ pserver.cc
@@ -32,6 +32,7 @@ along with this program; If not, see <ht
 #include <cmd-edit.h>
 #include <toplev.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -42,6 +43,8 @@ along with this program; If not, see <ht
 #include <netdb.h>
 #include <sys/utsname.h>
 #include <netinet/in.h> // reported necessary for FreeBSD-8
+#include <unistd.h>
+#include <stdlib.h>
 
 #if HAVE_UNISTD_H
 #include <unistd.h>
