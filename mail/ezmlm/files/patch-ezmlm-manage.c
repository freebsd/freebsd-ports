--- ezmlm-manage.c.orig	Sat Aug  2 13:07:10 2003
+++ ezmlm-manage.c	Sat Aug  2 13:07:30 2003
@@ -22,6 +22,7 @@
 #include "fmt.h"
 #include "subscribe.h"
 #include "cookie.h"
+#include "log.h"
 
 #define FATAL "ezmlm-manage: fatal: "
 void die_usage() { strerr_die1x(100,"ezmlm-manage: usage: ezmlm-manage dir"); }
