--- estic/imon.cc.orig	1996-11-08 16:41:46 UTC
+++ estic/imon.cc
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <errno.h>
 #include <sys/time.h>
+#include <unistd.h>
 
 #include "chartype.h"
 #include "itemwin.h"
