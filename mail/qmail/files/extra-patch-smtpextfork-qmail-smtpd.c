--- qmail-smtpd.c.orig	2013-02-05 21:28:49.477460299 -0600
+++ qmail-smtpd.c	2013-02-05 21:29:23.512455333 -0600
@@ -1,3 +1,4 @@
+#include <string.h>
 #include "readwrite.h"
 #include "stralloc.h"
 #include "substdio.h"
