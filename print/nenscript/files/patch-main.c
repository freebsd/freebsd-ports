--- main.c.orig	2008-07-19 14:32:26.000000000 -0500
+++ main.c	2008-07-19 14:34:12.000000000 -0500
@@ -601,7 +601,7 @@
       exit (1);
     }
 #else
-    sprintf (cmd, "%s %s", LPR, printername);
+    snprintf (cmd, sizeof(cmd), "%s %s", LPR, printername);
     if ((outputstream = popen (cmd, "w")) == NULL) {
       perror (LPR);
       exit (1);
