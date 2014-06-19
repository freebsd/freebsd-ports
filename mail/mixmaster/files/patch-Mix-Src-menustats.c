--- Mix/Src/menustats.c.orig	2014-06-16 23:20:42.000000000 +0200
+++ Mix/Src/menustats.c	2014-06-16 23:20:58.000000000 +0200
@@ -57,7 +57,7 @@
           narg[0]=WGET;
           narg[1]="-q";
           narg[2]=url;
-          narg[3]="-O";
+          narg[3]="-o";
           narg[4]=dest;
           narg[5]=(char *) 0;
           execvp(WGET, narg);
