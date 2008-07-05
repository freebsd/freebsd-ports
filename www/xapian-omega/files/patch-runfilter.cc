--- runfilter.cc.orig	2008-07-03 21:16:54.000000000 +0200
+++ runfilter.cc	2008-07-03 21:18:48.000000000 +0200
@@ -25,6 +25,7 @@
 #include "safeerrno.h"
 #include <sys/types.h>
 #include <stdio.h>
+#include <signal.h>
 #include "safefcntl.h"
 
 #ifdef HAVE_SYS_TIME_H
