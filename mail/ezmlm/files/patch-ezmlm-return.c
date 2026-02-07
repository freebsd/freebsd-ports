--- ezmlm-return.c.orig	Sat Aug  2 13:10:16 2003
+++ ezmlm-return.c	Sat Aug  2 13:10:31 2003
@@ -17,6 +17,7 @@
 #include "cookie.h"
 #include "subscribe.h"
 #include "issub.h"
+#include "log.h"
 
 #define FATAL "ezmlm-return: fatal: "
 void die_usage() { strerr_die1x(100,"ezmlm-return: usage: ezmlm-return dir"); }
