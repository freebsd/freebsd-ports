--- vncpasswd/vncpasswd.c.orig	2000-04-12 11:18:36.000000000 -0700
+++ vncpasswd/vncpasswd.c	2013-10-30 22:56:22.000000000 -0700
@@ -84,7 +84,7 @@
       }
       for (i = 0; i < strlen(passwd); i++)
 	passwd[i] = passwd1[i] = '\0';
-      return;
+      return (0);
     }
 
     fprintf(stderr,"They don't match. Try again.\n\n");
