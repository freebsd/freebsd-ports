--- medusa-idled/medusa-idled.c.orig	Fri Nov 15 02:08:09 2002
+++ medusa-idled/medusa-idled.c	Fri Nov 15 02:08:21 2002
@@ -32,11 +32,11 @@
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
-#include <sys/time.h>
-#include <sys/types.h>
 #include <sys/un.h>
 #include <time.h>
 #include <unistd.h>
