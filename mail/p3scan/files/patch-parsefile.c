--- parsefile.c.orig Wed Jan  5 20:53:04 2005
+++ parsefile.c      Tue Jul 26 11:10:08 2005
@@ -33,11 +33,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h>
 #include <sys/stat.h>
 #include "parsefile.h"
 #include "getline.h"
+#include <netinet/in.h>

 #define NONULL(x) ( x==NULL ? "" : x) /* this is nice, found in the mutt code */

