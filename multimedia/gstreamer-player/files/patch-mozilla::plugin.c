--- mozilla/plugin.c.orig	Sat Jul 12 05:27:40 2003
+++ mozilla/plugin.c	Sat Nov  8 14:10:11 2003
@@ -18,7 +18,12 @@
  */
 
 #include <stdio.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>
+#endif
+#include <signal.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/wait.h>
@@ -76,7 +81,7 @@
 		dup2(fds[2],0);
 		//dup2(fds[1],1);
 		
-		argv[argc++] = "gst-player";
+		argv[argc++] = "gst-player-gtk";
 		argv[argc++] = "--xid";
 		argv[argc++] = xid_str;
 		if(plugin->width){
@@ -92,8 +97,8 @@
 		argv[argc++] = "fd://0";
 		argv[argc] = NULL;
 
-		execvp("gst-player",argv);
-		execv(BINDIR "gst-player",argv);
+		execvp("gst-player-gtk",argv);
+		execv(BINDIR "gst-player-gtk",argv);
 		_exit(255);
 	}
 
