--- src/mem_freebsd.c.orig	Sun Sep 23 15:02:09 2001
+++ src/mem_freebsd.c	Sun Sep 23 15:02:51 2001
@@ -51,10 +51,10 @@
 
   if (geteuid () != getuid () || getegid () != getgid ())
     {
-      fprintf (stderr "unable to drop privileges");
+      fprintf (stderr,"unable to drop privileges");
       exit(1);
     }
-  return 0;
+  exit(1);
 }
 
 
