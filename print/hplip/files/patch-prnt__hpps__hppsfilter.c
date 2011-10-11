--- prnt/hpps/hppsfilter.c.orig	2011-10-11 17:25:10.000000000 +0300
+++ prnt/hpps/hppsfilter.c	2011-10-11 17:25:29.000000000 +0300
@@ -38,6 +38,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <cups/cups.h>
+#include <cups/ppd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
