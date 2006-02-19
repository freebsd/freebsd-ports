--- apps/ssh/sshfilecopy.c.orig	Wed Dec  3 14:17:25 2003
+++ apps/ssh/sshfilecopy.c	Sun Feb 19 20:33:18 2006
@@ -915,6 +915,7 @@
       /* This file is at it's end. */
       fprintf(stdout, "\r\n");
     }
+  fflush(stdout);
 }
 
 
