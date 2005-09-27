--- snmpd/main.c.orig	Thu Sep 22 09:14:31 2005
+++ snmpd/main.c	Thu Sep 22 09:15:49 2005
@@ -33,6 +33,7 @@
 #include <sys/param.h>
 #include <sys/un.h>
 #include <sys/ucred.h>
+#include <sys/uio.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
