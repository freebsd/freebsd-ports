--- ./sys/dvb/gstdvbsrc.c.orig	2010-09-07 18:04:03.000000000 +0200
+++ ./sys/dvb/gstdvbsrc.c	2010-09-07 18:04:12.000000000 +0200
@@ -45,7 +45,6 @@
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <fcntl.h>
-#include <error.h>
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
