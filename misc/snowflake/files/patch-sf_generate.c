--- sf_generate.c.orig	Sat Oct  7 16:21:57 2006
+++ sf_generate.c	Sat Oct  7 16:21:23 2006
@@ -16,6 +16,7 @@
 #include <sys/shm.h>
 #include <sys/sem.h>
 
+#include "getopt.h"
 #include "sf.h"
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
