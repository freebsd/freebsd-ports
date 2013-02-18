--- cmdline/getstatus.c.orig	2008-02-18 03:28:09.000000000 +0000
+++ cmdline/getstatus.c	2012-10-14 13:11:43.000000000 +0000
@@ -1,8 +1,9 @@
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <pthread.h>
 
-#include "afp.h"
+#include "afpfs-ng/afp.h"
 
 static int getstatus(char * address_string, unsigned int port)
 {
diff -Naur afpfs-ng-0.8.1.orig/configure.ac afpfs-ng-0.8.1/configure.ac
