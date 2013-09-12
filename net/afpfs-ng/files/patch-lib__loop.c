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
@@ -87,7 +87,7 @@ void signal_main_thread(void)
 static int ending=0;
 void * just_end_it_now(void * ignore)
 {
-	if (ending) return;
+	if (ending) return NULL;
 	ending=1;
 	if (libafpclient->forced_ending_hook) 
 		libafpclient->forced_ending_hook();
