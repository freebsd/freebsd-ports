--- ldapwrite.c.orig	Sat Jul  6 10:22:20 2002
+++ ldapwrite.c	Sat Jul  6 10:23:16 2002
@@ -24,6 +24,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
+
 #include "ldapdiff.h"
 #include "base64.h"
 
