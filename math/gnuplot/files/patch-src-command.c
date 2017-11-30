--- src/command.c.orig	2017-11-01 18:12:31.201708000 -0700
+++ src/command.c	2017-11-01 18:13:03.695758000 -0700
@@ -119,6 +119,7 @@
 
 #ifndef _Windows
 # include "help.h"
+# include <sys/wait.h>
 #endif /* _Windows */
 
 #ifdef _Windows
