--- main.c.orig	2016-06-30 19:23:33 UTC
+++ main.c
@@ -280,6 +280,12 @@ int runprogram( int argc, char *argv[] )
 	setsid();
         // This line makes the ptty our controlling tty. We do not otherwise need it open
         slavept=open(name, O_RDWR );
+#ifdef __FreeBSD__
+        if (ioctl(slavept, TIOCSCTTY, NULL) == -1) {
+            perror("sshpass: Failed to TIOCSCTTY");
+            exit(RETURN_RUNTIME_ERROR);
+        }
+#endif
         close( slavept );
 	
 	close( masterpt );
