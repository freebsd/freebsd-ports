--- authenticate/checkvpw.cc.orig	Mon Feb  2 14:51:35 2004
+++ authenticate/checkvpw.cc	Mon Feb  2 14:51:55 2004
@@ -16,6 +16,7 @@
 
 #include <config.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
 #include "config/configrc.h"
