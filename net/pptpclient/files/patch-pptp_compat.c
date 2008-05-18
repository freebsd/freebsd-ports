--- pptp_compat.c.orig	2008-05-19 03:44:02.000000000 +0800
+++ pptp_compat.c	2008-05-19 03:44:45.000000000 +0800
@@ -7,7 +7,7 @@
 #include <fcntl.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <stropts.h>
+#include <sys/un.h>
 #include <stdlib.h>
 #include <strings.h>
 #include "pptp_compat.h"
