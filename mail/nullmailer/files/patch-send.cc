--- src/send.cc.orig	Sun Aug 25 00:09:37 2002
+++ src/send.cc	Sun Aug 25 00:10:05 2002
@@ -30,6 +30,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#include <stdlib.h>
 #include "configio.h"
 #include "defines.h"
 #include "errcodes.h"
