--- ./src/mailbox.cc.orig	Sun Sep  3 13:08:05 2006
+++ ./src/mailbox.cc	Sun Sep  3 13:07:46 2006
@@ -30,6 +30,7 @@
 // ========================================================================
 
 #include <algorithm>
+#include <sys/types.h>
 #include <regex.h>
 #include "support.h"
 #include "mailbox.h"
