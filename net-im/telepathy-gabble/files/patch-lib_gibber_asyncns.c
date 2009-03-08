--- lib/gibber/asyncns.c.orig	2009-03-08 13:01:42.000000000 -0400
+++ lib/gibber/asyncns.c	2009-03-08 13:02:06.000000000 -0400
@@ -35,6 +35,7 @@
 #include <errno.h>
 #include <sys/wait.h>
 #include <sys/types.h>
+#include <sys/resource.h>
 #include <pwd.h>
 #include <netinet/in.h>
 #include <arpa/nameser.h>
