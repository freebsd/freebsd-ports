--- src/user.c.orig	Wed Apr 13 19:50:37 2005
+++ src/user.c	Mon Jul 18 14:55:59 2005
@@ -23,6 +23,7 @@
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 #include "monkey.h"
