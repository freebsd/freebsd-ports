--- parsefile.c.orig	Mon May  1 00:37:13 2006
+++ parsefile.c	Mon May  1 00:37:47 2006
@@ -69,9 +69,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
+#include <netinet/in.h>
 #include "parsefile.h"
 #include "getlinep3.h"
 #include "p3scan.h"
