--- ldapparse.c.orig	Sat Jul  6 10:21:57 2002
+++ ldapparse.c	Sat Jul  6 10:23:34 2002
@@ -25,6 +25,8 @@
 #include <stdlib.h>
 #include <errno.h>
 
+#include <sys/types.h>
+
 #include "ldapdiff.h"
 #include "base64.h"
 
