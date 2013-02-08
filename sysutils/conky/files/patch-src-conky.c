--- src/conky.c.orig	2012-05-04 00:22:21.000000000 +0300
+++ src/conky.c	2012-12-04 11:09:20.000000000 +0200
@@ -119,7 +119,7 @@
 #include "openbsd.h"
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
@@ -4292,7 +4292,8 @@
 
 	free_templates();
 
-	free(current_mail_spool);
+	if (current_mail_spool)
+		free(current_mail_spool);
 	{
 		char buf[256];
 
@@ -5662,6 +5663,7 @@
 			current_mail_spool = strndup(buf, text_buffer_size);
 		}
 	}
+	pthread_mutex_init(&kvm_proc_mutex, NULL);
 #endif
 
 	/* handle other command line arguments */
@@ -5971,7 +5973,7 @@
 
 void alarm_handler(void) {
 	if(childpid > 0) {
-		kill(childpid, SIGTERM);
+		kill(childpid, SIGKILL);
 	}
 }
 
