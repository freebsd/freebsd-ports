--- estic/imon.cc.orig	Sat Feb 26 18:33:03 2000
+++ estic/imon.cc	Sat Feb 26 18:33:29 2000
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <sys/time.h>
+#include <unistd.h>
 
 #include "chartype.h"
 #include "itemwin.h"
