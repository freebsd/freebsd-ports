--- src/conky.c.orig	2012-05-03 21:22:21 UTC
+++ src/conky.c
@@ -119,7 +119,7 @@
 #include "openbsd.h"
 #endif
 
-#if defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD_kernel__) && (__FreeBSD_kernel__ + 0)
 #include <bsd/bsd.h>
 #endif
 
@@ -4292,7 +4292,8 @@ static void set_default_configurations(v
 
 	free_templates();
 
-	free(current_mail_spool);
+	if (current_mail_spool)
+		free(current_mail_spool);
 	{
 		char buf[256];
 
@@ -5662,6 +5663,7 @@ void initialisation(int argc, char **arg
 			current_mail_spool = strndup(buf, text_buffer_size);
 		}
 	}
+	pthread_mutex_init(&kvm_proc_mutex, NULL);
 #endif
 
 	/* handle other command line arguments */
@@ -5971,7 +5973,7 @@ int main(int argc, char **argv)
 
 void alarm_handler(void) {
 	if(childpid > 0) {
-		kill(childpid, SIGTERM);
+		kill(childpid, SIGKILL);
 	}
 }
 
