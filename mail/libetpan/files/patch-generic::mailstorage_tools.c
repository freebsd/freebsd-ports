--- generic/mailstorage_tools.c.orig	Tue Dec  9 00:36:37 2003
+++ generic/mailstorage_tools.c	Thu Dec 11 00:04:20 2003
@@ -44,6 +44,7 @@
 #include <sys/wait.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
+#include <limits.h>
 
 #include "mailmessage.h"
 #include "maildriver.h"
