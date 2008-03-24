--- keyrings/gkr-keyrings.c.orig	2008-02-11 21:30:10.000000000 -0500
+++ keyrings/gkr-keyrings.c	2008-02-11 21:30:19.000000000 -0500
@@ -35,6 +35,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/types.h>
