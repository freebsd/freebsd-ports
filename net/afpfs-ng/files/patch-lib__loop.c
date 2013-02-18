--- lib/loop.c.orig	2008-02-18 03:40:11.000000000 +0000
+++ lib/loop.c	2012-10-14 13:11:44.000000000 +0000
@@ -16,16 +16,16 @@
 #include <sys/time.h>
 #include <signal.h>
 
-#include "afp.h"
-#include "dsi.h"
-#include "utils.h"
+#include "afpfs-ng/afp.h"
+#include "afpfs-ng/dsi.h"
+#include "afpfs-ng/utils.h"
 
 #define SIGNAL_TO_USE SIGUSR2
 
 static unsigned char exit_program=0;
 
 static pthread_t ending_thread;
-static pthread_t main_thread = NULL;
+static pthread_t main_thread = (pthread_t)NULL;
 
 static int loop_started=0;
 static pthread_cond_t loop_started_condition;
diff -Naur afpfs-ng-0.8.1.orig/lib/lowlevel.c afpfs-ng-0.8.1/lib/lowlevel.c
