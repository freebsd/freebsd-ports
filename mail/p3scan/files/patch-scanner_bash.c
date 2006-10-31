--- scanner_bash.c.orig	Mon May  1 00:54:39 2006
+++ scanner_bash.c	Mon May  1 00:54:55 2006
@@ -39,8 +39,8 @@
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <errno.h>
-#include <malloc.h>
 #include <pcre.h>
+#include <netinet/in.h>
 
 #include "p3scan.h"
 #include "parsefile.h"
