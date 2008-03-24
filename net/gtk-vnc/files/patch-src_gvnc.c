--- src/gvnc.c.orig	2008-02-22 09:33:46.000000000 -0500
+++ src/gvnc.c	2008-03-24 11:38:08.000000000 -0400
@@ -16,7 +16,7 @@
 
 #include <netdb.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <errno.h>
@@ -26,7 +26,6 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <endian.h>
 
 #include "coroutine.h"
 #include "d3des.h"
